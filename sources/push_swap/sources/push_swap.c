/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/26 23:57:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <string.h>


int				main(int ac, char **av)
{
	t_data			data;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (!init_app(&data, ac, av))
	{
		clear(&data);
		exit(EXIT_FAILURE);
	}
	if (!check_result(data.stack_a.list, data.stack_a.argc))
		(data.stack_a.argc < 8) ? resolve_shortlist(&data) :
									resolve_longlist(&data);

	//ft_lstiter(data.cmds, print_command);
	clear(&data);
	return (0);
}