/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:47:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/29 15:31:55 by mo0ky            ###   ########.fr       */
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
	//ft_printf("{red}START clear memomy alloc{eoc}\n");
	while (data->stack_a.list || data->stack_b.list)
	{
		//ft_printf("{lred}a->list(%p)\tb->list(%p){eoc}\n", data->stack_a.list, data->stack_b.list);
		if (data->stack_a.list)
		{
			//ft_printf("{lred}GO DEL a->list(%p)\n", data->stack_a.list);
			ft_lstdelfirst(&data->stack_a.list, &del_number);
		}
		if (data->stack_b.list)
		{
			//ft_printf("{lred}GO DEL b->list(%p)\n", data->stack_b.list);
			ft_lstdelfirst(&data->stack_b.list, &del_number);
		}
	}
}