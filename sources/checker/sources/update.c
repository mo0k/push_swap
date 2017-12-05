/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:20:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 13:06:26 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visual.h>

static void 	clear_window(t_win *win, int x_start, int y_start)
{
	int		y;
	int		x;

	x = x_start;
	y = y_start;
	if (x_start >= win->width - 1)
		return ;
	while((A_CHARTEXT & mvwinch(win->window, y, x)) == '|')
	{
		while((A_CHARTEXT & mvwinch(win->window, y, x)) == '|')
		{
			mvwaddch(win->window, y, x, ' ');
			y--;
		}
		++x;
		y = y_start;
	}
	wrefresh(win->window);
}

void		update_visual(t_display *display, t_list *stack_a, t_list *stack_b)
{
	int height;

	if (!display)
		return ;
	int x = 1;
	while (stack_a && x < display->main_top.width - 1)
	{
		height = display->main_top.height - 2 - ((((t_number*)(display->max->content))->value - ((t_number*)(stack_a->content))->value) * display->echelle);
		height = (height == 0) ? 1 : height;
		update_column(&display->main_top, x++, 1, height);
		stack_a = stack_a->next;
		wrefresh(display->main_top.window);
	}
	clear_window(&display->main_top, x, display->main_top.height - 2);
	x = 1;
	while (stack_b && x < display->main_bottom.width - 1)
	{
		height = display->main_bottom.height - 2 - ((((t_number*)(display->max->content))->value - ((t_number*)(stack_b->content))->value) * display->echelle);
		height = (height == 0) ? 1 : height;
		update_column(&display->main_bottom, x++, 1, height);
		stack_b = stack_b->next;
	}
	clear_window(&display->main_bottom, x, display->main_bottom.height - 2);
}

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
