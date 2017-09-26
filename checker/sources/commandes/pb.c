/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/27 01:23:27 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				do_pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !stack_a || !*stack_a)
		return ;
	ft_lstadd_start(stack_b, ft_lstnew((*stack_a)->content, sizeof(t_number)));
	ft_lstdelfirst(stack_a, &del_number);
}