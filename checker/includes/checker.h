/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/26 23:42:05 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <ft_printf.h>
# define NBR_INSTRUCTIONS 12

typedef void 		(*t_cmd)(t_list*, t_list*); 

typedef struct		s_options
{
	char			debug;
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
}					t_data;

void				print_prog_header(void);
void				print_stacks(t_list *stack_a, t_list *stack_b);

t_instruction		*get_tab_instruction(t_instruction *instruction);
int					find_instruction(t_instruction *instruction, char *cmd);

void				do_pa(t_list *stack_a, t_list *stack_b);
void				do_pb(t_list *stack_a, t_list *stack_b);
void				do_ra(t_list *stack_a, t_list *stack_b);
void				do_rb(t_list *stack_a, t_list *stack_b);
void				do_rr(t_list *stack_a, t_list *stack_b);
void				do_rra(t_list *stack_a, t_list *stack_b);
void				do_rrb(t_list *stack_a, t_list *stack_b);
void				do_rrr(t_list *stack_a, t_list *stack_b);
void				do_sa(t_list *stack_a, t_list *stack_b);
void				do_sb(t_list *stack_a, t_list *stack_b);
void				do_ss(t_list *stack_a, t_list *stack_b);

#endif