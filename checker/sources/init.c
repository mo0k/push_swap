/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:40:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/21 23:08:45 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static char **is_multi(char *value)
{
	char separator[5];
	char **split;
	int index;

	if (!value)
		return (NULL);
	separator[0] = '\v';
	separator[1] = '\n';
	separator[2] = '\t';
	separator[3] = ' ';
	separator[4] = 0;
	split = NULL;
	if ((ft_strchr(value, separator[0]) && (index = 0)) ||
		(ft_strchr(value, separator[1]) && (index = 1)) ||
		(ft_strchr(value, separator[2]) && (index = 2)) ||
		(ft_strchr(value, separator[3]) && (index = 3)))
	{
		if (!(split = ft_strsplit(value, separator[index])))
			return (NULL);
	}
	return (split);
}

static int 		parse(t_options *options, char *arg, t_uchar *flag)
{
	if (*arg == '-' && ft_isalpha(*(arg + 1)) && *flag == 1)
	{
		while (++arg && *arg)
		{
			if (*arg == 'v')
				options->verbose = 1;
			else if (*arg == 'f')
				options->log = 1;
			else if (*arg == 'c')
				options->color = 1;
			else if (*arg == 'r')
				options->display_result = 1;
			else
				return (-1);
		}
		return (0);
	}
	else
	{
		*flag = 0;
		if (*arg == '-')
			++arg;
		while (*arg)
		{
			if (!ft_isdigit(*arg))
				return (-1);
			++arg;
		}
		return (1);
	}
}

static void 		init_data(t_data *data)
{
	if (!data)
		return ;
	data->instruction = get_tab_instruction(data->instruction);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->options.verbose = 0;
	data->options.color = 0;
	data->options.display_result = 0;
	data->instruction_executed = 0;
	data->fd = 1;
	stock_data(data);
}

int 				parse_number(t_data *d, char *str_number, t_uchar *option)
{
	int 			ret;
	t_number		number;

	if (!d || !str_number || !option)
		return (-1);
	if ((ret = parse(&d->options, str_number, option)) == -1)
		return (-1);//return (0);
	else if (!ret)
		return (0); //continue;
	number.value = ft_atoi(str_number);
	ft_lstadd_end(&d->stack_a, ft_lstnew(&number, sizeof(number)));
	return (1);
}

static int 			tab2len(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (*tab)
	{
		++i;
		++tab;
	}
	return (i);
}
static int 			input(t_data *data, t_uchar *option, int ac, char **av)
{
	int				i;
	int 			result;
	char 			**split;

	i = 0;
	split = NULL;
	while (i < ac)
	{
		if ((split = is_multi(av[i])) != NULL)
		{
			input(data, option, tab2len(split), split);
			ft_delstrtab(split);
			i++;
			continue;
		}
		if((result = parse_number(data, av[i], option)) == -1)
			return (0);
		else if (!result)
		{
			i++;
			continue ;
		}
		i++;
	}
	return (1);
}

int					init(t_data *d, int ac, char **av)
{
	t_uchar			option;

	if (!d || !av || !*av)
		return (0);
	init_data(d);
	option = 1;
	if (!input(d, &option, ac -1, av+1))
		return (0);
	d->options.log = (d->options.log == 1 && !isatty(STDIN_FILENO) ? 1 : 0);
	if (d->options.log &&
		(d->fd = open("./log", O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
		return (0);
	d->nbr_arg = ft_lstlen(d->stack_a);
	return (1);
}