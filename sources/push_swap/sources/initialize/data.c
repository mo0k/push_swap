/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:45:28 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 21:12:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void 		init_data(t_data *data)
{
	if (!data)
		return ;
	init_stack(&data->stack_a, "stack_a");
	init_stack(&data->stack_b, "stack_b");
	data->argc = 0;
	data->fd = 1;
	data->cmds = NULL;
	stock_data(data);
}

t_data			*stock_data(t_data *data)
{
	static t_data	*stock;

	if (data)
		stock = data;
	else
		return (stock);
	return (data);
}
