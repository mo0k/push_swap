/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:47:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/23 23:13:30 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				del_number(void *content, size_t size)
{
	(void)size;
	free(content);
	content = NULL;
}

void				clear(t_data *data)
{
	while (data->stack_a.list || data->stack_b.list)
	{
		if (data->stack_a.list)
			ft_lstdelfirst(&data->stack_a.list, &del_number);
		if (data->stack_b.list)
			ft_lstdelfirst(&data->stack_b.list, &del_number);
	}
}