/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:20:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/27 22:43:02 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visual.h>

void 		update_column(t_win *win, int x_start, int y_start, int height)
{
	int win_height;

	if (!win)
		return ;
	win_height = win->height - 2;
	while (win_height - height)
	{
		mvwaddch(win->window, y_start++, x_start, ' ');
		win_height--;
	}
	while (height--)
	{
		if (mvwinch(win->window, y_start, x_start) != ' ')
		{
			return ;
		}
		else
		{
			wattron(win->window, COLOR_PAIR(8));
			mvwaddch(win->window, y_start, x_start, '|');
			wattroff(win->window, COLOR_PAIR(8));
		}
		y_start++;
	}
}
