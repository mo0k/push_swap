/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:20:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 12:43:54 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <win.h>


void	add_title(t_win *win, char *title, short color_pair)
{
	if (!win || !title)
		return ;
	wattron(win->window, color_pair);
	mvwprintw(win->window, 0, win->width / 2 - ft_strlen(title) / 2, title);
	wrefresh(win->window);
	wattroff(win->window, color_pair);
}

int 	initialize_window(t_win *win, int height, int width)
{
	if (!win)
		return (0);
	win->height = height;
	win->width = width;
	return (1);
}

int		create_window(t_win *win, int x_start, int y_start, short color_pair)
{
	if (!win)
		return (0);
	if (!(win->window = newwin(win->height, win->width, y_start, x_start)))
		return (0);
	wattron(win->window, color_pair);
	box(win->window, 0, 0);
	wrefresh(win->window);
	wattroff(win->window, color_pair);
	return (1);
}