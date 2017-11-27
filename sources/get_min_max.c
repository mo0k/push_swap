/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:28:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/25 21:33:21 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

t_list 				*get_min(t_list *list)
{
	//ft_printf("start get_min => %p\n", list);
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
	//ft_printf("end get_min => %d\n", ((t_number*)(temp->content))->index);

	return (temp);
}

t_list 				*get_max(t_list *list)
{
	//ft_printf("start get_max => %p\n", list);
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