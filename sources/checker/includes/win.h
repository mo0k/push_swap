/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 12:42:35 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_H
# define WIN_H

# include <win.h>
# include <curses.h>
# include <libft.h>

typedef struct	s_win{
	WINDOW		*window;
	int			height;
	int			width;
}				t_win;

int 			initialize_window(t_win *win, int height, int width);
int				create_window(t_win *win, int x_start, int y_start, short color_pair);
void			add_title(t_win *win, char *title, short color_pair);

#endif