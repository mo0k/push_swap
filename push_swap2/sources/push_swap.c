/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/11 13:20:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <string.h>

static int		exit_error(t_data *data)
{
	write(2, "Error\n", 6);
	clear(data);
	return (EXIT_FAILURE);
}

/*
int 			init_number(t_stack *stack, t_number *first, t_number *second, t_number *last)
{
	if (!first || !second || !last)
		return (0);
	first = stack->control.first ? stack->control.first->content : NULL;
	second = stack->control.second ? stack->control.second->content : NULL;
	last = stack->control.last ? stack->control.last->content : NULL;
	return (1);
}*/

int				main(int ac, char **av)
{
	t_data			data;
	int 			ret;

	if (ac < 2 || !init(&data, ac, av))
		return (exit_error(&data));
	ret = 0;
	print_control(data.stack_a.control);
	resolve(&data);
	print_stacks(&data.stack_a.list, &data.stack_b.list);
	ft_lstiter(data.cmds, print_command);
	clear(&data);
	ft_printf("nbr cmd:%d", ft_lstlen(data.cmds));
	return (0);
}