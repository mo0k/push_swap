/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:20:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/27 22:53:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>


static int		exit_error(char *error)
{
	endwin();
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

static void		set_color_pairs(void)
{
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_RED, COLOR_RED);
	init_pair(6, COLOR_BLACK, COLOR_WHITE);
	init_pair(7, COLOR_RED, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLUE);
}

static int		initialize_layout(t_display *display, int y_max, int x_max)
{
	if (!display)
		return (0);
	if (!initialize_window(&display->main_left, y_max / 2, x_max))
		return (0);
	if (!create_window(&display->main_left, 0, 0, COLOR_PAIR(1)))
		return (0);
	if (!initialize_window(&display->main_right, y_max / 2, x_max))
		return (0);
	if (!create_window(&display->main_right, 0, display->main_left.height, COLOR_PAIR(1)))
		return (0);
	return (1);
}

static int		initialize_stacks(t_display *display, t_list *stack_a, t_number *max)
{
	int height;

	add_title(&display->main_left, "PILE A", COLOR_PAIR(6));
	add_title(&display->main_right, "PILE B", COLOR_PAIR(6));
	if (!display)
		return (0);
	int x = 1;
	while (stack_a && x < display->main_left.width - 1)
	{
		height = display->main_left.height - 2 - ((max->value - ((t_number*)(stack_a->content))->value) * display->echelle);
		height = (height == 0) ? 1 : height; 
		update_column(&display->main_left, x++, 1, height);
		stack_a = stack_a->next;
	}
	wrefresh(display->main_left.window);
	return (1);
}

void			init_visual(t_display *display, t_list *stack_a)
{
	int		y_max;
	int		x_max;

	initscr();
	curs_set(0);
	if (!has_colors())
		exit_error("No color\n");
	start_color();
	set_color_pairs();
	getmaxyx(stdscr, y_max, x_max);
	refresh();
	display->min = get_min(stack_a);
	display->max = get_max(stack_a);
	if (y_max < 12)
		exit_error("Screen is too smaller\n");
	initialize_layout(display, y_max, x_max);
	display->echelle = ((float)display->main_left.height - 2) / (float)(((t_number*)(display->max->content))->value - ((t_number*)(display->min->content))->value);
	initialize_stacks(display, stack_a, display->max->content);
}
