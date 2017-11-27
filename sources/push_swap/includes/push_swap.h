/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/27 22:57:03 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <ft_printf.h>
# include <my_types.h>
# include <instructions.h>

typedef int 		(*t_condition)(int, t_list*, t_list*);

typedef struct 		s_command
{
	char 			*name;
}					t_command;

typedef struct 		s_control
{
	t_list			*first;
	t_list			*second;
	t_list			*last;
	t_list			*max;
	t_list			*min;
}					t_control;

typedef void 		(*t_cmd)(t_list**, t_list**);
typedef int 		(*t_ctrl_cmd)(t_control *control, t_list **alist, t_cmd func);

typedef struct		s_action
{
	int 			value;
	t_ctrl_cmd		ctrl_cmd;
	t_cmd			cmd;
}					t_action;

typedef struct		s_stack
{
	t_list			*list;
	int 			argc;
	char			name[10];
	t_control		control;
	t_action		action;
	t_condition		condition;
}					t_stack;

typedef struct		s_data
{
	t_stack			stack_a;
	t_stack			stack_b;
	int				argc;
	int				fd;
}					t_data;

/*
**	display
*/
void				print_stacks(t_list **stack_a, t_list **stack_b);
void				print_control(t_control control);
void				print_elem(t_list *elem);

/*
**	Initialize app
*/
int					init_app(t_data *data, int ac, char **av);
void				init_data(t_data *data);
void				init_stack(t_stack *stack, char *name);
int 				parse(t_data *data, char *str_number);
t_data				*stock_data(t_data *data);

/*
**	resolve
*/
int					check_result(t_list *stack, int nbr_arg);
int 				resolve_shortlist(t_data *data);
void 				sort_a_firsttime(t_stack *a, t_stack *b);
void 				sort_b(t_stack *b);
int 				resolve_longlist(t_data *data);
t_list 				*update_all_index_a(t_stack *a, t_stack *b);
t_list 				*update_all_index_b(t_stack *a, t_stack *b);
void				sort_controler(t_stack *a, t_stack *b);
void 				prepare_stack(t_stack *stack, int decale);
int					find_index(t_list *list, t_list *search);

/*
**	delete memory alloc
*/
void				del_number(void *list, size_t size);
void				clear(t_data *data);

/*
**	t_condition
*/
int					is_asc(int value, t_list *limit_1, t_list *limit_2);
int					is_desc(int value, t_list *limit_1, t_list *limit_2);

/*
**	utils
*/
int					get_rotate_control(t_action *action, t_stack *stack);
t_ctrl_cmd			get_rotate_ctrl_cmd(int *index, int argc);
t_cmd				get_rotate_cmd(t_ctrl_cmd ctrl_cmd, char *stackname);
t_list 				*get_min(t_list *list);
t_list 				*get_max(t_list *list);
t_list				*get_last(t_list *list);
long				spe_atoi(const char *str);
int					already_create(t_list *list, const int value);

/*
**	t_ctrl_cmd
**	Functions to call instructions (t_cmd)
**	and set controler's argument (t_control)
*/

int 				push_a(t_stack *stack_a, t_stack *stack_b);
int 				push_b(t_stack *stack_a, t_stack *stack_b);
int					rotate(t_control *control, t_list **alist, t_cmd func);
int					reverse_rotate(t_control *control, t_list **alist, t_cmd func);
int 				swap(t_control *control, t_list **alist, t_cmd func);
int 				double_rotate(t_stack *a, t_stack *b);
int 				double_reverse_rotate(t_stack *a, t_stack *b);
int 				double_swap(t_stack *a, t_stack *b);

#endif