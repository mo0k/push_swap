/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:07:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/25 11:20:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int 				rotate(t_stack *stack, t_cmd func)
{
	if (!stack || !func)
		return (0);
	stack->control.last =	stack->control.first;
	stack->control.first =	stack->control.second;
	stack->control.second =	(stack->control.second ?
											stack->control.second->next : 0);
	func(&stack->list, &stack->list);
	return (1);
}