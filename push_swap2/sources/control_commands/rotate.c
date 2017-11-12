/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:07:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/11 20:59:18 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//int 				rotate(t_stack *stack, t_cmd func)
int 			double_rotate(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	rotate(&a->control, &a->list, &do_ra);
	rotate(&b->control, &b->list, &do_rb);
	return (1);
}
int				rotate(t_control *control, t_list **alist, t_cmd func)
{
	if (!control || !alist || !func)
		return (0);
	control->last =	control->first;
	control->first = control->second;
	control->second = (control->second ? control->second->next : 0);
	func(alist, alist);
	return (1);
}

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

int			get_rotate_control(t_projection *projection, t_stack *stack)
{
	if (!projection || !stack)
		return (0);
	projection->ctrl_cmd = get_rotate_ctrl_cmd(&projection->value, stack->argc);
	if (!(projection->cmd = get_rotate_cmd(projection->ctrl_cmd, stack->name)))
		return (0);
	return (1);
}
