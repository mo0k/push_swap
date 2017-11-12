/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:07:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 12:16:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int 			double_rotate(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	rotate(&a->control, &a->list, &do_ra);
	rotate(&b->control, &b->list, &do_rb);
	return (1);
}

int				rotate(t_control *control, t_list **alist, t_cmd func)
{
	if (!control || !alist || !func)
		return (0);
	control->last =	control->first;
	control->first = control->second;
	control->second = (control->second ? control->second->next : 0);
	func(alist, alist);
	return (1);
}
