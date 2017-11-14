/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:07:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/13 20:06:01 by mo0ky            ###   ########.fr       */
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

t_list 				*get_min(t_list *list)
{
	//ft_printf("start get_min => %p\n", list);
	t_list		*temp;
	int 		index;

	if (!list)
		return (NULL);
	index = 0;
	temp = list;
	list = list->next;
	while (list)
	{
		if (((t_number*)(list->content))->value <
			((t_number*)(temp->content))->value)
			temp = list;
		list = list->next;
	}
	//ft_printf("end get_min => %d\n", ((t_number*)(temp->content))->index);

	return (temp);
}

t_list 				*get_max(t_list *list)
{
	//ft_printf("start get_max => %p\n", list);
	t_list		*temp;

	if (!list)
		return (NULL);
	temp = list;
	list = list->next;
	while (list)
	{
		if (((t_number*)(list->content))->value >
			((t_number*)(temp->content))->value)
			temp = list;
		list = list->next;
	}
	return (temp);
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
