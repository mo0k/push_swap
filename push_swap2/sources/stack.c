/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 22:39:13 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 12:12:25 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void 				*get_min(t_list *list)
{
	ft_printf("start get_min => %p\n", list);
	t_list		*temp;
	int 		index;

	if (!list)
		return (NULL);
	index = 0;
	temp = list;
	list = list->next;
	while (list)
	{
		if (((t_number*)(list->content))->value <
			((t_number*)(temp->content))->value)
			temp = list;
		list = list->next;
	}
	ft_printf("end get_min => %d\n", ((t_number*)(temp->content))->index);

	return (temp);
}

void 				*get_max(t_list *list)
{
	ft_printf("start get_max => %p\n", list);
	t_list		*temp;

	if (!list)
		return (NULL);
	temp = list;
	list = list->next;
	while (list)
	{
		if (((t_number*)(list->content))->value >
			((t_number*)(temp->content))->value)
			temp = list;
		list = list->next;
	}
	return (temp);
}