/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 14:14:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <ft_printf.h>

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

typedef struct		s_number
{
	int				value;
	int				index;
}					t_number;

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
	t_list			*cmds;
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
int 				resolve(t_data *data);

void				add_command(t_list **cmds, char *command_name);
void				print_command(t_list *elem);

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

/*
**	t_cmd
**	Instruction to move stacks
*/
void				do_pa(t_list **stack_a, t_list **stack_b);
void				do_pb(t_list **stack_a, t_list **stack_b);
void				do_ra(t_list **stack_a, t_list **stack_b);
void				do_rb(t_list **stack_a, t_list **stack_b);
void				do_rr(t_list **stack_a, t_list **stack_b);
void				do_rra(t_list **stack_a, t_list **stack_b);
void				do_rrb(t_list **stack_a, t_list **stack_b);
void				do_rrr(t_list **stack_a, t_list **stack_b);
void				do_sa(t_list **stack_a, t_list **stack_b);
void				do_sb(t_list **stack_a, t_list **stack_b);
void				do_ss(t_list **stack_a, t_list **stack_b);

#endif