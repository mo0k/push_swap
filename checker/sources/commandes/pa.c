/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/27 01:22:27 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				do_pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b || !*stack_b)
		return ;
	ft_lstadd_start(stack_a, ft_lstnew((*stack_b)->content, sizeof(t_number)));
	ft_lstdelfirst(stack_b, &del_number);
}
