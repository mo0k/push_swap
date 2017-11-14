/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/13 20:53:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <instructions.h>

void				do_rb(t_list **stack_a, t_list **stack_b)
{
	t_list			*first;
	t_list			*current;
	t_list			*next;

	(void)stack_a;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	next = first->next;
	*stack_b = next;
	(*stack_b)->prev = 0;
	current = *stack_b;
	while (current->next)
		current = current->next;
	current->next = first;
	first->prev = current;
	first->next = 0;
}

