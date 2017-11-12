/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 22:08:48 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <string.h>

static int		exit_error()
{
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_data			data;

	if (ac < 2)
		return (exit_error());
	if (!init_app(&data, ac, av))
	{
		clear(&data);
		return (exit_error());
	}
	//print_control(data.stack_a.control);
	resolve(&data);

//DEBUG DE FIN
	//print_stacks(&data.stack_a.list, &data.stack_b.list);
	ft_lstiter(data.cmds, print_command);
	//ft_printf("nbr cmd:%d", ft_lstlen(data.cmds));
//END DEBUG
	clear(&data);
	//while(1){};
	return (0);
}