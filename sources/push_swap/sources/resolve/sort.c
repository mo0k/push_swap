/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:19:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/15 00:51:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
**	The next two functions are using to determine if the value is in an interval
**
**	RETURN =>	1 for true;
**				0 for false;
*/

int	is_asc(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 || !limit_2)
		return (0);
	number_1 = limit_1->content;
	number_2 = limit_2->content;
	return ((value >= number_1->value && value < number_2->value) ? 1 : 0);
}

int	is_desc(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 || !limit_2)
		return (0);
	number_1 = limit_1->content;
	number_2 = limit_2->content;
	return ((value <= number_1->value && value > number_2->value) ? 1 : 0);
}

void 			sort_a_firsttime(t_stack *a, t_stack *b, t_list **acmds)
{
	//print_control(a->control);
	t_number *first;
	t_number *second;
	t_number *last;

	first = a->control.first ? a->control.first->content : NULL;
	second = a->control.second ? a->control.second->content : NULL;
	last = a->control.last ? a->control.last->content : NULL;
	if (last && first && first->value > last->value)
	{
		rotate(&a->control, &a->list, do_ra);
		add_command(acmds, "ra");
	}
	else if (last && second && second->value > last->value)
	{
		swap(&a->control, &a->list, do_sa);
		add_command(acmds, "sa");
		rotate(&a->control, &a->list, do_ra);
		add_command(acmds, "ra");
	}
	else if (first && second && first->value < second->value)
	{
		push_b(a, b);
		add_command(acmds, "pb");
	}
	else if (first && second && first->value > second->value)
	{
		swap(&a->control, &a->list, do_sa);
		add_command(acmds, "sa");
	}
}

void 			sort_b(t_stack *b, t_list **acmds)
{
	t_number *first;
	t_number *second;
	t_number *last;

	first = b->control.first ? b->control.first->content : NULL;
	second = b->control.second ? b->control.second->content : NULL;
	last = b->control.last ? b->control.last->content : NULL;
	if (last && first && first->value < last->value)
	{
		rotate(&b->control, &b->list, do_rb);
		add_command(acmds, "rb");
	}
	else if (last && second && second->value < last->value)
	{
		swap(&b->control, &b->list, do_sb);
		add_command(acmds, "sb");
		rotate(&b->control, &b->list, do_rb);
		add_command(acmds, "rb");
	}
	else if (first && second && first->value < second->value)
	{
		swap(&b->control, &b->list, do_sb);
		add_command(acmds, "sb");
	}
}
