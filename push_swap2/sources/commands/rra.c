/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/23 21:11:11 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				do_rra(t_list **stack_a, t_list **stack_b)
{
	t_list			*last;
	t_list			*prev;
	t_list			*current;

	(void)stack_b;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	current = *stack_a;
	while (current->next)
		current = current->next;
	last = current;
	last->next = *stack_a;
	prev = last->prev;
	last->prev = 0;
	current = *stack_a;
	current->prev = last;
	prev->next = 0;
	*stack_a = last;
}
