/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:49:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/13 23:57:28 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <libft.h>
# include <checker.h>

int		already_create(t_list *list, const int value)
{
	t_number	*number;
	if (!list)
		return (0);
	while (list)
	{
		number = list->content;
		if (number->value == value)
			return (1);
		list = list->next;
	}
	return (0);
}