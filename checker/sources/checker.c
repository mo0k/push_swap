/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/13 16:17:28 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <string.h>

static int exit_error(t_data *data)
{
	write(2, "Error\n", 6);
	clear_data(data);
	return (EXIT_FAILURE);
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

int 			run_checker(t_data *data, char **readline)
{
	int				index;

	//if (isatty(STDIN_FILENO))
	//	ft_dprintf(data->fd, "Instruction:\n");
	//if (print_prompt(data->options.color, data->fd) && get_next_line(0, readline))
	while (get_next_line(0, readline) > 0)
	{
		if ((data->options.log || !isatty(STDIN_FILENO)) && data->options.verbose)
			ft_dprintf(data->fd, "%s\n", *readline);
		if ((index = find_instruction(data->instruction, *readline)) > -1)
		{
			data->instruction[index].pfunc(&data->stack_a, &data->stack_b);
			if (data->options.verbose && index < NBR_INSTRUCTIONS - 2)
			{
				system("clear");
				print_stacks(&data->stack_a, &data->stack_b);
			}
			if (index < NBR_INSTRUCTIONS - 2 && ++data->instruction_executed &&
				index < NBR_INSTRUCTIONS - 1 && ((!isatty(STDIN_FILENO) && data->options.verbose) || isatty(STDIN_FILENO)))
					ft_dprintf(data->fd, "Instrucion N°%d\n", data->instruction_executed);
		}
	}
	//else
	//{
	ft_memdel((void*)(readline));
	if (!check_result(data->stack_a, data->nbr_arg))
	{
		if (data->options.display_result)
			print_stacks(&data->stack_a, &data->stack_b);
		write(data->fd, "KO\n", 3);
		return (0);
	}
		
	//}
	return (1);
}
int				main(int ac, char **av)
{
	t_data			data;
	char			*readline;
	//int 			ret;

	if (ac < 2)
		return (0);
	if (!init(&data, ac, av))
		return (exit_error(&data));
	//ret = 0;
	if (isatty(STDIN_FILENO) || data.options.verbose)
		print_prog_header(data.options.color, data.fd);
	//if (!check_result(data.stack_a, data.nbr_arg) && (ret = 1))
	//{
		if (!run_checker(&data, &readline))
		{
			clear_data(&data);
			return (1);
		}
	//}
	if (data.options.display_result)
		print_stacks(&data.stack_a, &data.stack_b);
	write(data.fd, "OK\n", 3);
	clear_data(&data);
	return (0);
}