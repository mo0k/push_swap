/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/27 13:22:57 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				do_sb(t_list **stack_a, t_list **stack_b)
{
	//ft_printf("{yellow}do_sb{eoc}\n");
	(void)stack_a;
	t_list	*tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = 0;
	tmp->prev = *stack_b;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if ((*stack_b)->next && (*stack_b)->next->next)
		(*stack_b)->next->next->prev = (*stack_b)->next;
}
