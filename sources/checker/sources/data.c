/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:35:01 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/27 21:49:30 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

t_data			*stock_data(t_data *data)
{
	static t_data	*stock;

	if (data)
		stock = data;
	else
		return (stock);
	return (data);
}

void			clear_data(t_data *data)
{
	while (data->stack_a || data->stack_b)
	{
		if (data->stack_a)
			ft_lstdelfirst(&data->stack_a, &del_number);
		if (data->stack_b)
			ft_lstdelfirst(&data->stack_b, &del_number);
	}
	if (data->fd > 2 && close(data->fd) == -1)
		ft_dprintf(2, "Error: close file\n");
}