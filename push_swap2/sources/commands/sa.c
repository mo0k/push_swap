/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/11 14:14:35 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				do_sa(t_list **stack_a, t_list **stack_b)
{
	ft_printf("{yellow}do_sa{eoc}\n");
	(void)stack_b;
	t_list	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
	{
		ft_printf("return ;\n");
		return ;
	}
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = 0;
	tmp->prev = *stack_a;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if ((*stack_a)->next && (*stack_a)->next->next)
		(*stack_a)->next->next->prev = (*stack_a)->next;
}
