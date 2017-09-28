/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/27 13:53:25 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				do_rrb(t_list **stack_a, t_list **stack_b)
{
	t_list			*last;
	t_list			*prev;
	t_list			*current;

	(void)stack_a;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	current = *stack_b;
	while (current->next)
		current = current->next;
	last = current;
	last->next = *stack_b;
	prev = last->prev;
	last->prev = 0;
	current = *stack_b;
	current->prev = last;
	prev->next = 0;
	*stack_b = last;
}
