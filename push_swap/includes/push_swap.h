/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/25 23:35:29 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <ft_printf.h>

typedef void 		(*t_cmd)(t_list**, t_list**); 

typedef struct 		s_commands
{
	char 			*name;
}					t_commands;

typedef struct		s_number
{
	int				value;
}					t_number;

typedef struct 		s_control
{
	t_list			*first;
	t_list			*second;
	t_list			*last;
}					t_control;

typedef struct		s_stack
{
	t_list			*list;
	int 			argc;
	t_control		control;
}					t_stack;

typedef struct		s_data
{
	t_stack			stack_a;
	t_stack			stack_b;
	int				argc;
	int				fd;
	t_list			*cmds;
}					t_data;

void				print_stacks(t_list **stack_a, t_list **stack_b);
void				print_control(t_control control);

int					init(t_data *data, int ac, char **av);
int 				parse(t_data *data, char *str_number);
t_data				*stock_data(t_data *data);

void				clear(t_data *data);
void				del_number(void *list, size_t size);

int 				push_a(t_stack *stack_a, t_stack *stack_b);
int 				push_b(t_stack *stack_a, t_stack *stack_b);
int 				rotate(t_stack *stack, t_cmd func);
int 				reverse_rotate(t_stack *stack, t_cmd func);
int 				swap(t_stack *stack, t_cmd func);

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