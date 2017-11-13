/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:35:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/13 15:43:28 by mo0ky            ###   ########.fr       */
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
	t_list 			*new;

	if (!d || !str_number)
		return (-1);
	if ((ret = do_parsing(str_number)) == -1)
		return (-1);
	//else if (!ret)
	//	return (0);
	if (ft_strlen(str_number) > 12)
		return (-1);

	long long nbr = spe_atoi(str_number);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (-1);
	number.value = (int)nbr;
	number.index = -1;
	ft_lstadd_end(&d->stack_a.list, (new = ft_lstnew(&number, sizeof(number))));
	//ft_printf("new number(%p)->content(%p):{red}%d{eoc}\n", new, new->content, number.value);
	//ft_printf("{lgreen}Value:%d{eoc}\n", number.value);
	if (!d->stack_a.control.min || number.value < ((t_number*)(d->stack_a.control.min->content))->value)
	{
		/*if (d->stack_a.control.min)
			ft_printf("{green}MIN:%d < %d{eoc}\n", number.value, ((t_number*)(d->stack_a.control.min->content))->value);
		else
			ft_printf("{lgreen}MIN:juste value:%d{eoc}\n", number.value);*/
		d->stack_a.control.min = new;
	}
	if (!d->stack_a.control.max || number.value > ((t_number*)(d->stack_a.control.max->content))->value)
	{
		/*if (d->stack_a.control.max)
			ft_printf("{green}MAX:%d > %d{eoc}\n", number.value, ((t_number*)(d->stack_a.control.max->content))->value);
		else
			ft_printf("{lgreen}MAX: juste value:%d{eoc}\n", number.value);*/
		d->stack_a.control.max = new;
	}
	return (1);
}