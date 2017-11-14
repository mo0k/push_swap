/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:18:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/13 22:45:40 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		calcul_index(int index, int argc)
{
	return ((index <= argc / 2) ? index : argc - index);
}

static int				get_new_pos(t_stack *stack, int value, t_condition condition)
{
	//ft_printf("{magenta}DEBUG | start get position et do rotate{eoc}\n");
	//int			temp;
	t_list		*list;
	int 		i;
	int 		state;
	int 		flag;

	if (!stack || !condition)
		return (0);
	i = 0;
	flag = 0;
	list = stack->list;
	state = ((stack->control.min && value < ((t_number*)(stack->control.min->content))->value) ||
			(stack->control.max && value > ((t_number*)(stack->control.max->content))->value)) ? 1 : 0;
	if (state)
		flag = 1;
	if (flag == 0 && list == stack->control.min)
		flag = 2;
	if (list)
	while (list)
	{
		if (list == stack->control.max)
			flag = 1;
		if (flag < 2 && !state && condition(value, list, list->next))
			return (i+1);
		else if (state && list == stack->control.max)
			return (i);
		else if (flag == 1 && !state && list == stack->control.min)
			return (i);
		if (flag == 0 && list == stack->control.min)
			flag = 2;
		list = list->next;
		++i;
	}
	return (0);
}

t_list 			*update_all_index(t_stack *a, t_stack *b)
{
	t_list		*list;
	t_list		*ret;
	//t_list		*ref;
	t_number 	*number;
	int 		index_new_pos;
	int 		i;
	int 		flag;
	int 		result;

	if (!a || !a->list)
		return (NULL);
	list = a->list;
	number = list->content;
	//number->index = 0;
	i = 0;
	ret = NULL;
	while (list)
	{
		index_new_pos = get_new_pos(b, number->value, b->condition);
		if (calcul_index(index_new_pos, b->argc) + calcul_index(i, a->argc) < index_new_pos &&
			calcul_index(index_new_pos, b->argc) + calcul_index(i, a->argc) < i && (flag = 1))
			result = calcul_index(index_new_pos, b->argc) + calcul_index(i, a->argc);
		else if ((flag = 2))
			result = (index_new_pos > i ? index_new_pos : i); 
		if (a->action.value == -1 || result < a->action.value + b->action.value)
		{
			ret = list;
			a->action.value = i;
			b->action.value = index_new_pos;
			if (flag == 1)
			{
				get_rotate_control(&a->action, a);
				get_rotate_control(&b->action, b);
			}
			else
			{
				a->action.ctrl_cmd = &rotate;
				b->action.ctrl_cmd = &rotate;
				a->action.cmd = &do_ra;
				b->action.cmd = &do_rb;
			}
		}
		++i;
		list = list->next;
		if (list)
		{
			number = list->content;
			//number->index = i;
		}
	}
	return (ret);
}

void				sort_controler(t_stack *a, t_stack *b, t_list **acmds)
{
	//ft_printf("start sort_controler\n");
	//sleep(5);
	char		cmd_name[4];

	if (!a || !b)
		return ;
	//if (a)
	//	printf("addr a.action.ctrl_cmd:%p\n", a->action.ctrl_cmd);
	//if (b)
	//	printf("addr b.action.ctrl_cmd:%p\n", b->action.ctrl_cmd);
	//ft_printf("debug 1 action\n");
	while ((a && b && (a->action.value > 0 || b->action.value > 0)) ||
			((!a && b && b->action.value > 0) || (!b && a && a->action.value > 0)))
	{
		if (a && b && a->action.value > 0 && b->action.value > 0 && a->action.ctrl_cmd == b->action.ctrl_cmd)
		{
			//ft_printf("action {cyan}rotate double{eoc}\n");
			ft_strcpy(cmd_name, (a->action.cmd == &do_ra ? "rr" : "rrr"));
			if (a->action.cmd == &do_ra)
				double_rotate(a, b);
			else
				double_reverse_rotate(a, b);
			add_command(acmds, cmd_name);
			--a->action.value;
			--b->action.value;
		}
		else if (a && a->action.value > 0)
		{
			//ft_printf("action {cyan}rotate a{eoc}\n");
			ft_strcpy(cmd_name, (a->action.cmd == &do_ra ? "ra" : "rra"));
			a->action.ctrl_cmd(&a->control, &a->list, a->action.cmd);
			add_command(acmds, cmd_name);
			--a->action.value;
		}
		else if (b && b->action.value > 0)
		{
			//ft_printf("action {cyan}rotate b{eoc}\n");
			ft_strcpy(cmd_name, (b->action.cmd == &do_rb ? "rb" : "rrb"));
			b->action.ctrl_cmd(&b->control, &b->list, b->action.cmd);
			add_command(acmds, cmd_name);
			--b->action.value;
		}
	}
}

int					find_index(t_list *list, t_list *search)
{
	int		i;

	i = 0;
	if (!list || !search)
		return (-1);
	while (list)
	{
		if (list == search)
			return (i);
		list = list->next;
		++i;
	}
	return (-1);
}

void 					prepare_stack(t_stack *stack, int decale, t_list **acmds)
{
	char		cmd_name[4];

	if (!stack || !acmds)
		return ;
	if (!ft_strcmp(stack->name, "stack_a"))
		ft_strcpy(cmd_name, (stack->action.ctrl_cmd == rotate ? "ra" : "rra"));
	else
		ft_strcpy(cmd_name, (stack->action.ctrl_cmd == rotate ? "rb" : "rrb"));
	while (decale-- > 0)
	{
		//ft_lstiter(stack->list, &print_elem);
		stack->action.ctrl_cmd(&stack->control, &stack->list ,stack->action.cmd);
		//ft_lstiter(stack->list, &print_elem);
		
		add_command(acmds, cmd_name);
	}
}

int 				resolve(t_data *data)
{
	t_list *min_action;

	if (!data)
		exit(EXIT_FAILURE);
	while (data->stack_a.list)
	{
		min_action = update_all_index(&data->stack_a, &data->stack_b);
		sort_controler(&data->stack_a, &data->stack_b, &data->cmds);
		push_b(&data->stack_a, &data->stack_b);
		add_command(&data->cmds, "pb");
		data->stack_a.action.value = -1;
		data->stack_b.action.value = -1;

	}
	data->stack_b.action.value = find_index(data->stack_b.list, data->stack_b.control.max);
	get_rotate_control(&data->stack_b.action, &data->stack_b);
	prepare_stack(&data->stack_b, data->stack_b.action.value, &data->cmds);
	while (data->stack_b.list)
	{
		push_a(&data->stack_a, &data->stack_b);
		add_command(&data->cmds, "pa");
	}
	return (1);
}