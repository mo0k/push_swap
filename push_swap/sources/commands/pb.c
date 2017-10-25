/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/24 21:54:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				do_pb(t_list **stack_a, t_list **stack_b)
{
	t_list *temp_a;
	t_list *temp_b;

	if (!stack_b || !stack_a || !*stack_a)
		return ;
	temp_b = *stack_b;
	temp_a = (*stack_a)->next;
	*stack_b = *stack_a;
	if (*stack_b)
		(*stack_b)->next = temp_b;
	if (temp_b)
		temp_b->prev = *stack_b;
	*stack_a = temp_a;
	if (*stack_a)
		(*stack_a)->prev = NULL;
}