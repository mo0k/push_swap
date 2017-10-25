/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:07:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/25 01:09:22 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int 				swap(t_stack *stack, t_cmd func)
{
	t_list *temp;

	if (!stack || !func)
		return (0);
	temp = stack->control.first;
	stack->control.first = stack->control.second;
	stack->control.second = temp;
	func(&stack->list, &stack->list);
	return (1);
}