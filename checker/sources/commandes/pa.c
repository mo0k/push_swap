/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/24 21:56:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				do_pa(t_list **stack_a, t_list **stack_b)
{
	t_list *temp_a;
	t_list *temp_b;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	temp_a = *stack_a;
	temp_b = (*stack_b)->next;
	*stack_a = *stack_b;
	if (*stack_a)
		(*stack_a)->next = temp_a;
	if (temp_a)
		temp_a->prev = *stack_a;
	*stack_b = temp_b;
	if (*stack_b)
		(*stack_b)->prev = NULL;
}
