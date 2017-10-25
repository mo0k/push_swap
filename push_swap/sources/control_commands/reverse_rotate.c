/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 23:33:00 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/25 23:35:30 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int 				reverse_rotate(t_stack *stack, t_cmd func)
{
	t_list	*temp;

	if (!stack || !func)
		return (0);
	if (!stack->control.first || !stack->control.last)
		return (0);
	temp = stack->control.last;
	stack->control.last =	stack->control.last ? stack->control.last->prev : 0;
	stack->control.second = stack->control.first;
	stack->control.first =	temp;
	func(&stack->list, &stack->list);
	return (1);
}
