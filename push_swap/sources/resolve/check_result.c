/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:31:03 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 12:17:18 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				check_result(t_list *stack, int nbr_arg)
{
	t_list			*next;
	t_number		*a;
	t_number		*b;
	int				i;

	if (!stack)
		return (0);
	i = 1;
	while (stack)
	{
		if (!(next = stack->next))
			break;
		i++;
		a = (t_number*)(stack->content);
		b = (t_number*)(next->content);
		if (a->value > b->value)
			return (0);
		stack = stack->next;
	}
	return ((i == nbr_arg) ? 1 : 0);
}
