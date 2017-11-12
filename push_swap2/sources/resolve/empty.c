/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:20:23 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/09 09:06:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			prepare_b(t_stack *a, t_stack *b, t_list **acmds)
{
	//printf("DEBUG | start empty_stack_b\n");
	t_number 	*first;
	t_number 	*second;
	t_number 	*last;
	//t_projection	projct[3];

	first = b->control.first ? b->control.first->content : NULL;
	second = b->control.second ? b->control.second->content : NULL;
	last = b->control.last ? b->control.last->content : NULL;

	if (first)
		first->gap.value = get_gap(a, first, a->control.min, 0);
	ft_printf("{lgreen}first:%d\tctrl_cmd:%p\tcmd:%p\n{eoc}", first->gap.value, first->gap.ctrl_cmd, first->gap.cmd);
	if (second)
		second->gap.value = get_gap(a, second, a->control.min, 0) + 1;
	ft_printf("{lgreen}second:%d\tctrl_cmd:%p\tcmd:%p\n{eoc}", second->gap.value, second->gap.ctrl_cmd, second->gap.cmd);
	if (last)
		last->gap.value = get_gap(a, last, a->control.min, 0) + 1;
	ft_printf("{lgreen}last:%d\tctrl_cmd:%p\tcmd:%p\n{eoc}", last->gap.value, last->gap.ctrl_cmd, last->gap.cmd);
	int i = 0;
	if (first->gap.value < second->gap.value && first->gap.value < last->gap.value)
		i = 0;
	else if (second && second->gap.value < first->gap.value && second->gap.value < last->gap.value)
	{
		--second->gap.value;
		i = 1;
	}
	else if (last && last->gap.value < first->gap.value && last->gap.value < second->gap.value)
	{
		--last->gap.value;
		i = 2;
	}
	if (i == 0)
	{
		return (first->gap.value);
	}
	if (i == 1)
	{
		swap(&b->control, &b->list, &do_sb);
		add_command(acmds, "sb");
		return (second->gap.value);
	}
	else if (i == 2)
	{
		reverse_rotate(&b->control, &b->list, &do_rrb);
		add_command(acmds, "rrb");
		return (last->gap.value);
	}
	else
		return (-1);
	//push_a(a, b);
	//add_command(acmds, "pa");
//	print_stacks(&a->list, &b->list);
//	ft_printf("{green}projct[%d]:%d\n{eoc}", i, projct[i].gap);
	//a->ctrl_cmd = projct[i].ctrl_cmd;
	//a->cmd = projct[i].cmd;
//	return (projct[i].gap);
}
