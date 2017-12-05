/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:20:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 13:10:26 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int		print_error(char *error)
{
	//endwin();
	write(2, error, ft_strlen(error));
	return (0);
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
	if (!initialize_window(&display->main_top, y_max / 2, x_max))
		return (0);
	if (!create_window(&display->main_top, 0, 0, COLOR_PAIR(1)))
		return (0);
	if (!initialize_window(&display->main_bottom, y_max / 2, x_max))
		return (0);
	if (!create_window(&display->main_bottom, 0, display->main_top.height, COLOR_PAIR(1)))
		return (0);
	return (1);
}

static int		initialize_stacks(t_display *display, t_list *stack_a, t_number *max)
{
	int height;

	add_title(&display->main_top, "PILE A", COLOR_PAIR(6));
	add_title(&display->main_bottom, "PILE B", COLOR_PAIR(6));
	if (!display)
		return (0);
	int x = 1;
	while (stack_a && x < display->main_top.width - 1)
	{
		height = display->main_top.height - 2 - ((max->value - ((t_number*)(stack_a->content))->value) * display->echelle);
		height = (height == 0) ? 1 : height; 
		update_column(&display->main_top, x++, 1, height);
		stack_a = stack_a->next;
	}
	wrefresh(display->main_top.window);
	return (1);
}

int			init_visual(t_display *display, t_list *stack_a)
{
	int		y_max;
	int		x_max;

	if (!display || !stack_a)
		return (0);
	initscr();
	curs_set(0);
	if (!has_colors())
		return (print_error("No color\n"));
	start_color();
	set_color_pairs();
	getmaxyx(stdscr, y_max, x_max);
	refresh();
	display->min = get_min(stack_a);
	display->max = get_max(stack_a);
	if (y_max < 12)
		return (print_error("Screen is too smaller\n"));
	initialize_layout(display, y_max, x_max);
	display->echelle = ((float)display->main_top.height - 2)
						/ (float)(((t_number*)(display->max->content))->value
							- ((t_number*)(display->min->content))->value);
	initialize_stacks(display, stack_a, display->max->content);
	return (1);
}
