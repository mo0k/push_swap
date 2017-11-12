/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 00:38:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/28 14:17:27 by mo0ky            ###   ########.fr       */
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
	if (stack_b->control.min == stack_a->list)
		stack_b->control.min = get_min(stack_b->list);
	if (stack_b->control.max == stack_a->list)
		stack_b->control.max = get_max(stack_b->list);
	if (!stack_a->control.min || (stack_a->list &&
		((t_number*)(stack_a->list->content))->value < ((t_number*)(stack_a->control.min->content))->value))
		stack_a->control.min = stack_a->list;
	if (!stack_a->control.max || (stack_a->list &&
		((t_number*)(stack_a->list->content))->value > ((t_number*)(stack_a->control.max->content))->value))
		stack_a->control.max = stack_a->list;
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
	if (stack_a->control.min == stack_b->list)
		stack_a->control.min = get_min(stack_a->list);
	ft_printf("Apres get min push b\n");
	if (stack_a->control.max == stack_b->list)
		stack_a->control.max = get_max(stack_a->list);
	ft_printf("Apres get max push b\n");
	if (!stack_b->control.min || (stack_b->list &&
		((t_number*)(stack_b->list->content))->value < ((t_number*)(stack_b->control.min->content))->value))
	{
		ft_printf("push b -> avant assign control->min:%p | max:%p b->list:%p\n", stack_b->control.min, stack_b->control.max, stack_b->list);
		stack_b->control.min = stack_b->list;
		ft_printf("push b -> apres assign control->min:%p | max:%p b->list:%p\n", stack_b->control.min, stack_b->control.max, stack_b->list);
	}
	if (!stack_b->control.max || (stack_b->list &&
		((t_number*)(stack_b->list->content))->value > ((t_number*)(stack_b->control.max->content))->value))
	{
		ft_printf("push b -> assign control->max\n");
		stack_b->control.max = stack_b->list;
	}
	ft_printf("par la\n");
	ft_printf("Fin push b -> min:%p, max:%p\n", stack_b->control.min, stack_b->control.max);
	return (1);
}