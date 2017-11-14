/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:07:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 11:57:19 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int 			double_swap(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	swap(&a->control, &a->list, &do_sa);
	swap(&b->control, &b->list, &do_sb);
	return (1);
}

int 			swap(t_control *control, t_list **alist, t_cmd func)
{
	t_list *temp;

	if (!control || !alist || !func)
		return (0);
	temp = control->first;
	control->first = control->second;
	control->second = temp;
	func(alist, alist);
	return (1);
}