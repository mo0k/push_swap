/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/27 22:55:13 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <libft.h>
# include <curses.h>
# include <my_types.h>
# include <win.h>

typedef struct	s_display{
	t_win		main_win;
	t_win		main_left;
	t_win		main_middle;
	t_win		main_right;
	t_list		*min;
	t_list		*max;
	float		echelle;
}				t_display;

void			init_visual(t_display *display, t_list *a);
void			update_visual(t_display *display, t_list *a, t_list *b);

void 			update_column(t_win *win, int x_start, int y_start, int height);

#endif