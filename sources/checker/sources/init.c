/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:40:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/15 12:44:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void 		init_data(t_data *data)
{
	if (!data)
		return ;
	data->instruction = get_tab_instruction(data->instruction);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->options.verbose = 0;
	data->options.log = 0;
	data->options.color = 0;
	data->options.display_result = 0;
	data->instruction_executed = 0;
	data->fd = 1;
	stock_data(data);
}

static char			**is_multi(char *value)
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
		if((result = parse(data, av[i], option)) == -1)
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