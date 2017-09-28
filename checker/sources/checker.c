/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/28 20:43:37 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <string.h>

static int exit_error(t_data *data)
{
	write(2, "Error\n", 6);
	clear_alloc(data);
	return (EXIT_FAILURE);
}

static int 		parse(t_options *options, char *arg, t_uchar *flag)
{
	if (!arg)
		return (-1);
	if (*arg == '-' && *flag == 1)
	{
		while (++arg && *arg)
		{
			if (*arg == 'v')
				options->verbose = 1;
			else if (*arg == 'f')
				options->log = 1;
			else if (*arg == 'c')
				options->color = 1;
			else
				return (-1);
		}
		return (0);
	}
	else if (*arg == '-' && *flag == 0)
		return (-1);
	else
	{
		*flag = 0;
		return (1);
	}
}
static int		init(t_data *data, int ac, char **av)
{
	int				i;
	t_number		number;
	int 			ret;
	t_uchar			option;

	if (!data || !av || !*av)
		return (0);
	data->instruction = get_tab_instruction(data->instruction);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->options.verbose = 0;
	data->options.log = 0;
	data->options.color = 0;
	data->instruction_executed = 0;
	data->fd = 1;
	stock_data(data);
	option = 1;
	i = 0;
	while (++i < ac)
	{
		if ((ret = parse(&data->options, av[i], &option)) == -1)
			return (0);
		else if (!ret)
			continue;
		number.value = ft_atoi(av[i]);
		ft_lstadd_end(&data->stack_a, ft_lstnew(&number, sizeof(number)));
	}
	if (data->options.log && (data->fd = open("./log", O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
		return (0);
	data->nbr_arg = ft_lstlen(data->stack_a);
	return (1);
}
int				check_result(t_list *stack, int nbr_arg)
{
	t_list			*next;
	t_number		*a;
	t_number		*b;
	int				i;

	if (!stack)
		return (0);
	i = 1;
	while (stack)
	{
		if (!(next = stack->next))
			break;
		i++;
		a = (t_number*)(stack->content);
		b = (t_number*)(next->content);
		if (a->value > b->value)
			return (0);
		stack = stack->next;
	}
	return ((i == nbr_arg) ? 1 : 0);
}
t_data			*stock_data(t_data *data)
{
	static t_data	*stock;

	if (data)
		stock = data;
	else
		return (stock);
	return (data);
}
int 			run_checker(t_data *data, char **readline)
{
	int				index;

	if (print_prompt(data->options.color, data->fd) && get_next_line(0, readline))
	{
		if (data->options.log || !isatty(STDIN_FILENO))
			ft_dprintf(data->fd, "%s\n", *readline);
		if ((index = find_instruction(data->instruction, *readline)) > -1)
		{
			data->instruction[index].pfunc(&data->stack_a, &data->stack_b);
			if (data->options.verbose && index < NBR_INSTRUCTIONS - 2)
				print_stacks(&data->stack_a, &data->stack_b);
			if (index < NBR_INSTRUCTIONS - 2 && ++data->instruction_executed &&
				index < NBR_INSTRUCTIONS - 1)
					ft_dprintf(data->fd, "Instrucion N°%d\n", data->instruction_executed);
		}
	}
	else
	{
		write(data->fd, "KO\n", 3);
		return (0);
	}
	ft_memdel((void*)(readline));
	return (1);
}
int				main(int ac, char **av)
{
	t_data			data;
	char			*readline;

	if (ac < 2 || !init(&data, ac, av))
		return (exit_error(&data));
	print_prog_header(data.options.color, data.fd);
	while (!check_result(data.stack_a, data.nbr_arg))
	{
		if (!run_checker(&data, &readline))
		{
			clear_alloc(&data);
			return (1);
		}
	}
	if (!data.options.verbose)
		print_stacks(&data.stack_a, &data.stack_b);
	write(data.fd, "OK\n", 3);
	clear_alloc(&data);
	return (0);
}