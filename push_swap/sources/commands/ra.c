/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/23 21:10:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				do_ra(t_list **stack_a, t_list **stack_b)
{
	t_list			*first;
	t_list			*current;
	t_list			*next;

	(void)stack_b;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	next = first->next;
	*stack_a = next;
	(*stack_a)->prev = 0;
	current = *stack_a;
	while (current->next)
		current = current->next;
	current->next = first;
	first->prev = current;
	first->next = 0;
}
