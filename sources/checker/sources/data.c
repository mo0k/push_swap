/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:35:01 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/15 20:48:42 by mo0ky            ###   ########.fr       */
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
