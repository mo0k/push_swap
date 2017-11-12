/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:45:28 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 21:13:23 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void 		init_stack(t_stack *stack, char *name)
{
	if (!stack)
		return ;
	ft_strcpy(stack->name, name);
	//ft_printf("{red}%s\n{eoc}", stack->name);
	stack->list = NULL;
	stack->argc = 0;
	stack->control.first = NULL;
	stack->control.second = NULL;
	stack->control.last = NULL;
	stack->control.min = NULL;
	stack->control.max = NULL;
	stack->action.value = -1;
	stack->action.cmd = NULL;
	stack->action.ctrl_cmd = NULL;
	stack->condition = (!ft_strcmp(name, "stack_a") ? &is_asc : &is_desc);
}
