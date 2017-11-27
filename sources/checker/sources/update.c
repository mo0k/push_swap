/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:20:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/27 22:46:38 by mo0ky            ###   ########.fr       */
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
	while (stack_a && x < display->main_left.width - 1)
	{
		height = display->main_left.height - 2 - ((((t_number*)(display->max->content))->value - ((t_number*)(stack_a->content))->value) * display->echelle);
		height = (height == 0) ? 1 : height;
		update_column(&display->main_left, x++, 1, height);
		stack_a = stack_a->next;
		wrefresh(display->main_left.window);
	}
	clear_window(&display->main_left, x, display->main_left.height - 2);
	x = 1;
	while (stack_b && x < display->main_right.width - 1)
	{
		height = display->main_right.height - 2 - ((((t_number*)(display->max->content))->value - ((t_number*)(stack_b->content))->value) * display->echelle);
		height = (height == 0) ? 1 : height;
		update_column(&display->main_right, x++, 1, height);
		stack_b = stack_b->next;
	}
	clear_window(&display->main_right, x, display->main_right.height - 2);
}