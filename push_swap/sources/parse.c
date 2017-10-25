/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:35:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/23 23:12:41 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int 		do_parsing(char *arg)
{
		if (*arg == '-')
			++arg;
		while (*arg)
		{
			if (!ft_isdigit(*arg))
				return (-1);
			++arg;
		}
		return (1);
}

int 				parse(t_data *d, char *str_number)
{
	int 			ret;
	t_number		number;

	if (!d || !str_number)
		return (-1);
	if ((ret = do_parsing(str_number)) == -1)
		return (-1);
	else if (!ret)
		return (0);
	number.value = ft_atoi(str_number);
	ft_lstadd_end(&d->stack_a.list, ft_lstnew(&number, sizeof(number)));
	return (1);
}