/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/13 20:53:18 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include <libft.h>

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