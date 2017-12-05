/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:48:21 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 13:02:42 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int 		exit_error(t_data *data)
{
	if (data->options.ncurse)
		endwin();
	write(2, "Error\n", 6);
	clear_data(data);
	while (1){};
	exit(EXIT_FAILURE);
}

int 		exit_prog(t_data *data, int exit_status)
{
	if (!data)
		return (EXIT_FAILURE);
	if (data->options.ncurse)
		endwin();
	clear_data(data);
	write((exit_status ? 2 : 1), (exit_status ? "KO\n" : "OK\n"), 3);
	while (1){};
	return (exit_status);
}	
