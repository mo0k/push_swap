/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 00:38:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/25 10:29:33 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int 				push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (0);
	stack_b->control.first = stack_b->list->next;
	stack_b->control.second = (stack_b->control.first) ? stack_b->control.first->next : NULL;
	stack_b->control.last = stack_b->control.second ? stack_b->control.last : NULL;
	stack_b->argc = (stack_b->argc > 0) ? stack_b->argc - 1 : 0;
	do_pa(&stack_a->list, &stack_b->list);
	stack_a->control.first = stack_a->list;
	stack_a->control.second = (stack_a->control.first) ? stack_a->control.first->next : NULL;
	stack_a->control.last = stack_a->control.second ? stack_a->control.last : NULL;
	stack_a->argc++;
	return (1);
}

int 				push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (0);
	stack_a->control.first = stack_a->list->next;
	stack_a->control.second = (stack_a->control.first) ? stack_a->control.first->next : NULL;
	stack_a->control.last = !stack_a->control.last ? stack_a->control.second : stack_a->control.last;
	stack_a->argc = (stack_a->argc > 0) ? stack_a->argc - 1 : 0;
	do_pb(&stack_a->list, &stack_b->list);
	stack_b->control.first = stack_b->list;
	stack_b->control.second = (stack_b->control.first) ? stack_b->control.first->next : NULL;
	stack_b->control.last = !stack_b->control.last ? stack_b->control.second : stack_b->control.last;
	stack_b->argc++;
	return (1);
}