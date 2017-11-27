/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:07:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/25 21:29:00 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


t_ctrl_cmd		get_rotate_ctrl_cmd(int *index, int argc)
{
	if (*index <= argc / 2)
	{
		//ft_printf("1 {lred}index=%d\t(argc/2)=%d\n{eoc}", *index, argc/2);
		return (&rotate);
	}
	else
	{
		//ft_printf("2 {lred}index:%d\targc:%d\n{eoc}", *index, argc);
		*index = argc - *index;
		return (&reverse_rotate);
	}
}

t_cmd		get_rotate_cmd(t_ctrl_cmd ctrl_cmd, char *stackname)
{
	if (ctrl_cmd == &rotate)
		return (!ft_strcmp(stackname, "stack_a") ? &do_ra : &do_rb);
	else if (ctrl_cmd == &reverse_rotate)
		return (!ft_strcmp(stackname, "stack_a") ? &do_rra : &do_rrb);
	else
		return (NULL);
}

int			get_rotate_control(t_action *action, t_stack *stack)
{
	if (!action || !stack)
		return (0);
	action->ctrl_cmd = get_rotate_ctrl_cmd(&action->value, stack->argc);
	if (!(action->cmd = get_rotate_cmd(action->ctrl_cmd, stack->name)))
		return (0);
	return (1);
}


t_list				*get_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (!list->next)
			return (list);
		list = list->next;
	}
	return (NULL);
}
