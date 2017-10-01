/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 13:34:36 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <ft_printf.h>

# define NBR_INSTRUCTIONS 13
# define OPTIONS "v"

typedef void 		(*t_cmd)(t_list**, t_list**); 

typedef struct		s_options
{
	t_uchar			verbose;
	t_uchar			log;
	t_uchar			color;
	t_uchar			display_result;
}					t_options;

typedef struct		s_instruction
{
	char			name[10];
	t_cmd			pfunc;
}					t_instruction;

typedef struct		s_number
{
	int				value;
}					t_number;

typedef struct		s_data
{
	t_instruction 	*instruction;
	t_list			*stack_a;
	t_list			*stack_b;
	t_options		options;
	int				nbr_arg;
	int				instruction_executed;
	int				fd;
}					t_data;

void				print_prog_header(t_uchar log, int fd);
int					print_prompt(t_uchar log, int fd);
void				print_stacks(t_list **stack_a, t_list **stack_b);
void				print_help(t_list **stack_a, t_list **stack_b);
//void				print_stacks_col(int fd, t_list **stack_a, t_list **stack_b);

t_data				*stock_data(t_data *data);
t_instruction		*get_tab_instruction(t_instruction *instruction);
int					find_instruction(t_instruction *instruction, char *cmd);

void				clear(t_data *data);
void				del_number(void *list, size_t size);

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