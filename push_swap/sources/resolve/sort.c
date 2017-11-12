/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:19:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 12:28:02 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
**	The next two functions are using to determine if the value is in an interval
**
**	RETURN =>	1 for true;
**				0 for false;
*/

int	is_asc(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 || !limit_2)
		return (0);
	number_1 = limit_1->content;
	number_2 = limit_2->content;
	return ((value >= number_1->value && value < number_2->value) ? 1 : 0);
}

int	is_desc(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 || !limit_2)
		return (0);
	number_1 = limit_1->content;
	number_2 = limit_2->content;
	return ((value <= number_1->value && value > number_2->value) ? 1 : 0);
}
/*
int	is_asc_1(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 && !limit_2)
		return (0);
	else if (limit_1 && limit_2)
	{
		number_1 = limit_1->content;
		number_2 = limit_2->content;
		return ((value > number_1->value && value < number_2->value) ? 1 : 0);
	}
	else if (limit_1)
	{
		number_1 = limit_1->content;
		return ((value > number_1->value) ? 1 : 0);
	}
	return (0);
}

int	is_desc_1(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 && !limit_2)
		return (0);
	else if (limit_1 && limit_2)
	{
		number_1 = limit_1->content;
		number_2 = limit_2->content;
		return ((value < number_1->value && value > number_2->value) ? 1 : 0);
	}
	else if (limit_1)
	{
		number_1 = limit_1->content;
		return ((value < number_1->value) ? 1 : 0);
	}
	return (0);
}
*/