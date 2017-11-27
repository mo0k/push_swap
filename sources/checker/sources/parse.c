/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:35:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/24 23:09:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int 		do_parsing(t_options *options, char *arg, t_uchar *flag)
{
	if (*arg == '-' && ft_isalpha(*(arg + 1)) && *flag == 1)
	{
		while (++arg && *arg)
		{
			if (*arg == 'v')
				options->verbose = 1;
			else if (*arg == 'n')
			{
				options->ncurse = 1;
			}
			else if (*arg == 'f')
				options->log = 1;
			else if (*arg == 'c')
				options->color = 1;
			else if (*arg == 'r')
				options->display_result = 1;
			else
				return (-1);
		}
		return (0);
	}
	else
	{
		*flag = 0;
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
}

int 				parse(t_data *d, char *str_number, t_uchar *option)
{
	int 			ret;
	t_number		number;

	if (!d || !str_number || !option)
	{
		return (-1);
	}
	if ((ret = do_parsing(&d->options, str_number, option)) == -1)
		return (-1);
	else if (!ret)
		return (0);
	long long nbr = spe_atoi(str_number);
	if (nbr < -2147483648 || nbr > 2147483647 || already_create(d->stack_a, (int)nbr))
		return (-1);
	number.value = (int)nbr;
	ft_lstadd_end(&d->stack_a, ft_lstnew(&number, sizeof(number)));
	return (1);
}