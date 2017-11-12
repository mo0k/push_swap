/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 23:33:00 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 12:16:40 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int 			double_reverse_rotate(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	reverse_rotate(&a->control, &a->list, &do_rra);
	reverse_rotate(&b->control, &b->list, &do_rrb);
	return (1);
}

int				reverse_rotate(t_control *control, t_list **alist, t_cmd func)
{
	t_list	*temp;

	if (!control || !alist || !func)
		return (0);
	if (!control->first || !control->last)
		return (0);
	temp = control->last;
	control->last =	control->last ? control->last->prev : 0;
	control->second = control->first;
	control->first = temp;
	func(alist, alist);
	return (1);
}
