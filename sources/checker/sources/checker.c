/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 13:03:12 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

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

void 			do_instruction(t_data *data, int index)
{
	if (!data)
		return ;
	data->instruction[index].pfunc(&data->stack_a, &data->stack_b);
	if (data->options.ncurse)
		update_visual(&data->display, data->stack_a, data->stack_b);
	if (data->options.verbose && index < NBR_INSTRUCTIONS - 2)
		print_stacks(&data->stack_a, &data->stack_b);
	if (index < NBR_INSTRUCTIONS - 2 && ++data->instruction_executed &&
			index < NBR_INSTRUCTIONS - 1 && 
			((!isatty(STDIN_FILENO) && data->options.verbose) ||
				isatty(STDIN_FILENO)))
		ft_dprintf(data->fd, "Instrucion N°%d\n", data->instruction_executed);
}

int 			run_checker(t_data *data, char **readline)
{
	int				index;

	while (get_next_line(0, readline) > 0)
	{
		if ((data->options.log || !isatty(STDIN_FILENO)) && data->options.verbose)
			ft_dprintf(data->fd, "%s\n", *readline);
		if ((index = find_instruction(data->instruction, *readline)) > -1)
			do_instruction(data, index);
		else
			return (exit_error(data));
		ft_memdel((void*)(readline));
	}
	if (!check_result(data->stack_a, data->nbr_arg))
	{
		if (data->options.display_result)
			print_stacks(&data->stack_a, &data->stack_b);
		return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_data			data;
	char			*readline;

	if (ac < 2)
		return (0);
	if (!init(&data, ac, av))
		return (exit_error(&data));
	if (data.options.ncurse && !init_visual(&data.display, data.stack_a))
		return (exit_error(&data));
	if (isatty(STDIN_FILENO) || data.options.verbose)
		print_prog_header(data.options.color, data.fd);
	if (!run_checker(&data, &readline))
		return (exit_prog(&data, EXIT_FAILURE));
	if (data.options.display_result)
		print_stacks(&data.stack_a, &data.stack_b);
	return (exit_prog(&data, EXIT_SUCCESS));
}
