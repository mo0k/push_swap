/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:19:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/11 23:17:41 by mo0ky            ###   ########.fr       */
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

int	is_asc_1(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 && !limit_2)
		return (0);
	else if (limit_1 && limit_2)
	{
		number_1 = limit_1->content;
		number_2 = limit_2->content;
		return ((value > number_1->value && value < number_2->value) ? 1 : 0);
	}
	else if (limit_1)
	{
		number_1 = limit_1->content;
		return ((value > number_1->value) ? 1 : 0);
	}
	return (0);
}

int	is_desc_1(int value, t_list *limit_1, t_list *limit_2)
{
	t_number	*number_1;
	t_number	*number_2;

	if (!limit_1 && !limit_2)
		return (0);
	else if (limit_1 && limit_2)
	{
		number_1 = limit_1->content;
		number_2 = limit_2->content;
		return ((value < number_1->value && value > number_2->value) ? 1 : 0);
	}
	else if (limit_1)
	{
		number_1 = limit_1->content;
		return ((value < number_1->value) ? 1 : 0);
	}
	return (0);
}


/*
**	This function determines the new position of the value in the list
**	The value argument is a number to place
**	The ref argument is a min value(stack_a) or max value(stack_b)
**	The condition argument is a function pointer to find a new position
**					- is_asc() for stack_a
**					- is_desc() for stack_b
**	RETURN =>	Difference between the start and new position
*/
//static int				get_new_pos(t_list *list, int value, t_list *ref, t_condition condition)
static int				get_new_pos(t_stack *stack, int value, t_list *ref, t_condition condition)
{
	//ft_printf("{magenta}DEBUG | start get position et do rotate{eoc}\n");
	int			temp;
	t_list		*list;
	int 		i;
	int 		ret;
	int 		state;
	int 		flag;

	if (!stack)
		return (0);
	i = 0;
	ret = 0;
	flag = 0;
	temp = value;
	list = stack->list;
	//state = (value <= ((t_number*)(ref->content))->value) ? 1 : 0;
	state = ((condition == &is_asc_1 && value < ((t_number*)(ref->content))->value) ||
			(condition == &is_desc_1 && value > ((t_number*)(ref->content))->value) ||
			(condition == &is_asc && value <= ((t_number*)(ref->content))->value) ||
			(condition == &is_desc && value >= ((t_number*)(ref->content))->value)) ? 1 : 0;
	if (list == ref)
		flag = 1;
	if (flag == 0 && ((ref == stack->control.min && list == stack->control.max && !ft_strcmp(stack->name, "stack_a")) ||
			(ref == stack->control.max && list == stack->control.min && !ft_strcmp(stack->name, "stack_b"))))
		flag = 2;
	//ft_printf("avant while list value:%d\ttemp:%d\tref:%p\tstate:%d\n", ((t_number*)(list->content))->value, temp, ref, state);
	while (list)
	{
		//ft_printf("IN while list value:%d\ttemp:%d\tflag:%d\n", ((t_number*)(list->content))->value, temp, flag);
		//if (!state && temp > ((t_number*)(list->content))->value && (!list->next || temp < ((t_number*)(list->next->content))->value))
		if (list == ref)
			flag = 1;
		//if (flag == 0 && ((ref == stack->control.min && list == stack->control.max && !ft_strcmp(stack->name, "stack_a")) ||
		//	(ref == stack->control.max && list == stack->control.min && !ft_strcmp(stack->name, "stack_b"))))
		//	flag = 2;
		if (flag < 2 && !state && condition(temp, list, list->next))
		{
			//if (((t_number*)(list->content))->value == value)
			//	return (0);
			ret = i;
			//ft_printf("ret:%d\n", ret);
			return (i+1);
		}
		else if (state && ref == list)
			return (i);
		else if (flag == 1 && !state && ((ref == stack->control.min && list == stack->control.max && !ft_strcmp(stack->name, "stack_a")) ||
					(ref == stack->control.max && list == stack->control.min && !ft_strcmp(stack->name, "stack_b"))))
			return (i);
		if (flag == 0 && ((ref == stack->control.min && list == stack->control.max && !ft_strcmp(stack->name, "stack_a")) ||
			(ref == stack->control.max && list == stack->control.min && !ft_strcmp(stack->name, "stack_b"))))
			flag = 2;
			//return (i+1);
			//return (((t_number*)(list->content))->value == value ? 0 : i);
		list = list->next;
		++i;
	}
	//ft_printf("2 return:%d\n", i-1);
	return (0);
	//return (ret);
}

//int 			get_nbr_cmd(t_stack *stack, int value, t_projection *projct)
int 				get_gap(t_stack *stack, t_number *number, t_list *ref, int number_index)//int value, t_ctrl_cmd *ctrl_cmd, t_cmd *cmd)
{
	int			diff;
	//int argc = 

	//diff = get_new_pos(stack->list, number->value, stack->control.min);
	diff = get_new_pos(stack, number->value, ref, stack->condition);
		//number_index++;
	//ft_printf("{green}diff:%d\n{eoc}", diff);
	if (number_index <= diff)
	{
		//ft_printf("{red}index <= diff => %d <= %d\n{eoc}", number_index, diff);
		if (diff - number_index <= stack->argc / 2)
		{
			//ft_printf("1 {lred}diff=%d\tnumber_index:%d\targc=%d\targc/2:%d\n{eoc}", diff, number_index, stack->argc, stack->argc/2);
			number->gap.ctrl_cmd = &rotate;
			number->gap.cmd = !ft_strcmp(stack->name, "stack_a") ? &do_ra : &do_rb;
		}
		else
		{
			//ft_printf("2 {lred}diff=%d\tnumber_index:%d\targc=%d\targc/2:%d\n{eoc}", diff, number_index, stack->argc, stack->argc/2);
			number->gap.ctrl_cmd = &reverse_rotate;
			number->gap.cmd = !ft_strcmp(stack->name, "stack_a") ? &do_rra : &do_rrb;
		}
		return ((diff - number_index <= stack->argc / 2) ? diff - ++number_index: stack->argc - diff + number_index);
	}
	else
	{
		//ft_printf("{red}number_index > diff => %d > %d\n{eoc}", number_index, diff);
		if (number_index - diff <= stack->argc / 2)
		{
			//ft_printf("3 {lred}diff=%d\tnumber_index:%d\targc=%d\targc/2:%d\n{eoc}", diff, number_index, stack->argc, stack->argc/2);
			number->gap.ctrl_cmd = &reverse_rotate;
			number->gap.cmd = !ft_strcmp(stack->name, "stack_a") ? &do_rra : &do_rrb;
		}
		else
		{
			//ft_printf("4 {lred}diff=%d\tnumber_index:%d\targc=%d\targc/2:%d\n{eoc}", diff, number_index, stack->argc, stack->argc/2);
			number->gap.ctrl_cmd = &rotate;
			number->gap.cmd = !ft_strcmp(stack->name, "stack_a") ? &do_ra : &do_rb;
		}
		return ((number_index - diff <= stack->argc / 2) ? number_index - diff: stack->argc - ++number_index + diff);
	}
	//if (number_index > diff)
	/*if (number_index <= diff && diff <= stack->argc / 2)
	{
		ft_printf("1 {lred}diff=%d\targc/2=%d\n{eoc}", diff, stack->argc/2);
		number->ctrl_cmd = &rotate;
		number->cmd = !ft_strcmp(stack->name, "stack_a") ? &do_ra : &do_rb;
	}
	else
	{
		ft_printf("2 {lred}diff:%d\targc:%d\n{eoc}", diff, stack->argc);
		number->ctrl_cmd = &reverse_rotate;
		number->cmd = !ft_strcmp(stack->name, "stack_a") ? &do_rra : &do_rrb;
	}
	ft_printf("{red}return gap:%d\n", ((diff <= stack->argc / 2) ? diff : stack->argc - diff));
	return ((number_index <= diff && diff <= stack->argc / 2) ? diff : stack->argc - diff);*/
}

int 				get_index(t_stack *stack, t_list *ref)//int value, t_ctrl_cmd *ctrl_cmd, t_cmd *cmd)
{
	t_list	*list;
	int		index;

	if (!stack || !stack->list)
		return (-1);
	index = 0;
	list = stack->list;
	while (list)
	{
		if (list == ref)
			return (index);
		list = list->next;
		++index;
	}
	return (-1);
}

void 					prepare_stack(t_stack *stack, int decale, t_list **acmds, t_number *new)
{
	ft_printf("{cyan}DEBUG | start PREPARE A =>decale:%d{eoc}\n", decale);
	char		cmd_name[4];

	if (!stack || !acmds)
		return ;
	ft_printf("{lblue}stack:%p\tra:%p\trra:%p\n{eoc}", new->index.cmd, &do_ra, &do_rra);
	ft_strcpy(cmd_name, (new->index.cmd == &do_ra ? "ra" : "rra"));
	while (decale-- > 0)
	{
		ft_printf("apply function : %s\n", cmd_name);
		ft_printf("{lred}PRINT CONTROL A\n{eoc}");
		print_control(stack->control);
		ft_printf("{lred}PRINT CONTROL B\n{eoc}");
		print_control(stock_data(NULL)->stack_b.control);
		print_stacks(&stack->list, &stock_data(NULL)->stack_b.list);
		
		ft_printf("{cyan}AVANT mouvement{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(stack->list, &print_elem);
		new->index.ctrl_cmd(&stack->control, &stack->list ,new->index.cmd);
		ft_printf("{cyan}APRES mouvement{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(stack->list, &print_elem);
		
		add_command(acmds, cmd_name);
		print_control(stack->control);
		print_stacks(&stack->list, &stock_data(NULL)->stack_b.list);
	}
	ft_printf("{cyan}DEBUG | FIN PREPARE A{eoc}\n");
}

void				sort_controler(t_data *data, t_number *a, t_number *b)
{
	ft_printf("start sort_controler\n");
	//sleep(5);
	char		cmd_name[4];

	//if (!a || !b)
	//	return ;
	if (a)
		printf("addr a.index.ctrl_cmd:%p\n", a->index.ctrl_cmd);
	if (b)
		printf("addr b.index.ctrl_cmd:%p\n", b->index.ctrl_cmd);
	ft_printf("debug 1 INDEX\n");
	while ((a && b && (a->index.value > 0 || b->index.value > 0)) ||
			((!a && b && b->index.value > 0) || (!b && a && a->index.value > 0)))
	{
		if (a && b && a->index.value > 0 && b->index.value > 0 && a->index.ctrl_cmd == b->index.ctrl_cmd)
		{
			ft_printf("index {cyan}rotate double{eoc}\n");
			ft_strcpy(cmd_name, (a->index.cmd == &do_ra ? "rr" : "rrr"));
			if (a->index.cmd == &do_ra)
				double_rotate(&data->stack_a, &data->stack_b);
			else
				double_reverse_rotate(&data->stack_a, &data->stack_b);
			add_command(&data->cmds, cmd_name);
			--a->index.value;
			--b->index.value;
		}
		else if (a && a->index.value > 0)
		{
			ft_printf("index {cyan}rotate a{eoc}\n");
			ft_strcpy(cmd_name, (a->index.cmd == &do_ra ? "ra" : "rra"));
			a->index.ctrl_cmd(&data->stack_a.control, &data->stack_a.list, a->index.cmd);
			add_command(&data->cmds, cmd_name);
			--a->index.value;
		}
		else if (b && b->index.value > 0)
		{
			ft_printf("index {cyan}rotate b{eoc}\n");
			ft_strcpy(cmd_name, (b->index.cmd == &do_rb ? "rb" : "rrb"));
			b->index.ctrl_cmd(&data->stack_b.control, &data->stack_b.list, b->index.cmd);
			add_command(&data->cmds, cmd_name);
			--b->index.value;
		}
	}
	print_stacks(&data->stack_a.list, &data->stack_b.list);
	ft_printf("debug 2 GAP\n");
	while ((a && b && (a->gap.value > 0 || b->gap.value > 0)) ||
			((!a && b && b->gap.value > 0) || (!b && a && a->gap.value > 0)))
	{
		if ((a && a->gap.value > 1 && a->gap.ctrl_cmd == &reverse_rotate) ||
			(b && b->gap.value > 1 && b->gap.ctrl_cmd == &reverse_rotate))
		{
			ft_printf("gap {cyan}reverse rotate{eoc}\n");
			if (a && b && a->gap.ctrl_cmd == b->gap.ctrl_cmd)
			{
				double_reverse_rotate(&data->stack_a, &data->stack_b);
				add_command(&data->cmds, "rrr");
			}
			else 
			{
				if (a && a->gap.ctrl_cmd == &reverse_rotate)
				{
					a->gap.ctrl_cmd(&data->stack_a.control, &data->stack_a.list, a->gap.cmd);
					add_command(&data->cmds, "rra");
				}
				if (b && b->gap.ctrl_cmd == &reverse_rotate)
				{
					b->gap.ctrl_cmd(&data->stack_b.control, &data->stack_b.list, b->gap.cmd);
					add_command(&data->cmds, "rrb");
				}
			}
			print_stacks(&data->stack_a.list, &data->stack_b.list);
		}
		ft_printf("gap -> swap\n");
		if (a && b && a->gap.value > 0 && b->gap.value > 0)
		{
			ft_printf("{cyan}double swap{eoc}\n");
			double_swap(&data->stack_a, &data->stack_b);
			add_command(&data->cmds, "ss");
		}
		else if (a && a->gap.value > 0)
		{
			ft_printf("{cyan}swap a{eoc}\n");
			swap(&data->stack_a.control, &data->stack_a.list, &do_sa);
			add_command(&data->cmds, "sa");
		}
		else if (b && b->gap.value > 0)
		{
			ft_printf("{cyan}swap b{eoc}\n");
			swap(&data->stack_b.control, &data->stack_b.list, &do_sb);
			add_command(&data->cmds, "sb");
		}
		print_stacks(&data->stack_a.list, &data->stack_b.list);
		if ((a && a->gap.value > 1 && a->gap.ctrl_cmd == &rotate) ||
			(b && b->gap.value > 1 && b->gap.ctrl_cmd == &rotate))
		{
			ft_printf("gap {cyan}rotate{eoc}\n");
			if (a && b && a->gap.ctrl_cmd == b->gap.ctrl_cmd)
			{
				double_rotate(&data->stack_a, &data->stack_b);
				add_command(&data->cmds, "rr");
			}
			else 
			{
				if (a && a->gap.ctrl_cmd == &rotate)
				{
					a->gap.ctrl_cmd(&data->stack_a.control, &data->stack_a.list, a->gap.cmd);
					add_command(&data->cmds, "ra");
				}
				if (b && b->gap.ctrl_cmd == &rotate)
				{
					b->gap.ctrl_cmd(&data->stack_b.control, &data->stack_b.list, b->gap.cmd);
					add_command(&data->cmds, "rb");
				}
			}
			print_stacks(&data->stack_a.list, &data->stack_b.list);
		}
		if (a)
			a->gap.value -= 2;
		if (b)
			b->gap.value -= 2;
		//sleep(5);
	}

	if (a)
		a->place = 1;
	if (b)
		b->place = 1;
	return ;
}
/*
void 					sort_a_secondtime2(t_stack *a, t_number *number, t_list **acmds)
{
	ft_printf("{cyan}DEBUG | start get position et do rotate{eoc}\n");

	int			diff;
	t_cmd		cmd;
	t_ctrl_cmd	ctrl_cmd;
	char		cmd_name[4];

	if (!a || !acmds)
		return ;
	diff = get_new_pos(a->list, number->value, a->control.min);
	int count = (diff <= a->argc / 2) ? diff : a->argc - diff;
	ft_printf("diff:%d\n", diff);
	if (diff <= a->argc / 2)
	{
		ft_printf("choix function => rotate & ra\n");
		cmd = &do_ra;
		ctrl_cmd = &rotate;
		ft_strcpy(cmd_name, "ra");
	}
	else
	{
		//diff = (diff > 0) ? --diff : diff;
		cmd = &do_rra;
		ctrl_cmd = &reverse_rotate;
		ft_printf("choix function => reverse rotate & rra\n");
		ft_strcpy(cmd_name, "rra");
	}
	ft_printf("{lred}count:%d\n{eoc}", count);
	while (count--)
	{
		ft_printf("apply function : %s\n", cmd_name);
		print_control(a->control);
		print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
		
		ft_printf("{cyan}AVANT mouvement{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ctrl_cmd(a, cmd);
		ft_printf("{cyan}AVANT mouvement{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		
		add_command(acmds, cmd_name);
		print_control(a->control);
		print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
	}
}
*/
void 			sort_a_secondtime(t_stack *a, int *count, t_list **acmds)
{
	//ft_printf("{red}start sort_a_secondtime{eoc}\n");
	//print_control(a->control);
	t_number *first;
	t_number *second;
	t_number *last;

	first = a->control.first ? a->control.first->content : NULL;
	second = a->control.second ? a->control.second->content : NULL;
	last = a->control.last ? a->control.last->content : NULL;
	//ft_printf("DEBUG | 1 first(%p):%d\tsecond(%p):%d\n", first, first->value ,second, second->value);
	//if (first && second && first->value > second->value)
	//{
		while (first && second && first->value > second->value)
		{
			//ft_printf("DEBUG | 2 first(%p):%d\tsecond(%p):%d\n", first, first->value ,second, second->value);
			swap(&a->control, &a->list, do_sa);
			add_command(acmds, "sa");
			//print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
			if (!check_result(a->list, a->argc))
			{
				rotate(&a->control, &a->list, do_ra);
				add_command(acmds, "ra");
				//print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
				++(*count);

				//ft_printf("count:%d\n", *count);
				//sort_a_secondtime(&a->control, &a->list, count);
			}
			else
			{
				*count = 0;
				break ;
			}
			first = a->control.first ? a->control.first->content : NULL;
			second = a->control.second ? a->control.second->content : NULL;
			last = a->control.last ? a->control.last->content : NULL;
		}
	//}
	//else if (first && last && first->value > last->value && *count > 0)
	//{
		//ft_printf("DEBUG | 1 first(%p):%d\tlast(%p):%d\n", first, first->value ,last, last->value);
		while (first && last && first->value < last->value && *count)
		{
			//ft_printf("DEBUG | 2 first(%p):%d\tlast(%p):%d\n", first, first->value ,last, last->value);
			reverse_rotate(&a->control, &a->list, do_rra);
			add_command(acmds, "rra");
			//print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
			swap(&a->control, &a->list, do_sa);

			add_command(acmds, "sa");
			//print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
			if (check_result(a->list, a->argc))
			{
				*count = 0;
				break;
			}
			--(*count);
			first = a->control.first ? a->control.first->content : NULL;
			second = a->control.second ? a->control.second->content : NULL;
			last = a->control.last ? a->control.last->content : NULL;
		}
	//}
	//ft_printf("{blue}count:%d{eoc}\n", *count);
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
		ft_printf("{cyan}AVANT ROTATE_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);
		rotate(&a->control, &a->list, do_ra);
		ft_printf("{cyan}APRES ROTATE A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);

		add_command(acmds, "ra");
	}
	else if (last && second && second->value > last->value)
	{
		ft_printf("{cyan}AVANT SWAP_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);
		swap(&a->control, &a->list, do_sa);
		ft_printf("{cyan}APRES SWAP_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);

		add_command(acmds, "sa");

		ft_printf("{cyan}AVANT ROTATE_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);
		rotate(&a->control, &a->list, do_ra);
		ft_printf("{cyan}APRES ROTATE A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);

		add_command(acmds, "ra");
	}
	else if (first && second && first->value < second->value)
	{
		ft_printf("{cyan}AVANT PUSH_B{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);
		push_b(a, b);
		ft_printf("{cyan}APRES PUSH_B{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);
		add_command(acmds, "pb");
		sort_b(b, acmds);
	}
	else if (first && second && first->value > second->value)
	{
		ft_printf("{cyan}AVANT SWAP_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);
		swap(&a->control, &a->list, do_sa);
		ft_printf("{cyan}APRES SWAP_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(a->list, &print_elem);
		ft_printf("{magenta}FT_LSTITER B{eoc}\n");
		ft_lstiter(b->list, &print_elem);

		add_command(acmds, "sa");
	}
}

void 			sort_b(t_stack *b, t_list **acmds)
{
	//ft_printf("start sort b\n");
	//print_control(b->control);
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
