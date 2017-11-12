/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:19:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/11 22:46:00 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
/*
static int		calcul_index(int index, int argc)
{
	return ((index <= argc / 2) ? index : argc - index);
}*/
/*
** calcul all gap in the list and return the smaller
*/
t_list 			*update_all_gap(t_stack *s)
{
	t_list		*list;
	t_list		*ret;
	t_list		*ref;
	t_number 	*number;
	int 		i;

	if (!s || !s->list)
		return (NULL);
	i = 0;
	ref = !ft_strcmp(s->name, "stack_a") ? s->control.min : s->control.max;
	list = s->list;
	number = list->content;
	number->gap.value = get_gap(s, list->content, ref, 0);
	number->index.value = 0;
	//ft_printf("{red}total gap + calcul_index:%d\n{eoc}", (((t_number*)(list->content))->gap.value * 2) + calcul_index(i, s->argc));
	//ft_printf("{red}total gap*2:%d\n{eoc}", ((t_number*)(list->content))->gap.value * 2);
	ret = !number->place && number->gap.value > 0 ? list : NULL;
	while (list)
	{
		//ft_printf("{blue}debut while\n{eoc}");
		//ft_printf("{blue}place:%d\tvalue:%d\n{eoc}", number->place, number->value);
		if (!number->place && number->gap.value > 0 &&
			!s->condition(number->value, list->prev, list->next) &&
			(!ret || (number->gap.value * 2) + number->index.value <
			(((t_number*)(ret->content))->gap.value * 2) +
			((t_number*)(ret->content))->index.value))
		{
			ret = list;
		}
		++i;
		list = list->next;
		if (list)
		{
			number = list->content;
			number->gap.value = get_gap(s, list->content, ref, i);
			number->index.value = i;
			number->index.ctrl_cmd = get_rotate_ctrl_cmd(&number->index.value, s->argc);
			number->index.cmd = get_rotate_cmd(number->index.ctrl_cmd, s->name);
		//ft_printf("{red}total gap + calcul_index:%d\n{eoc}", (number->gap.value * 2) + calcul_index(i, s->argc));
		//ft_printf("{red}total gap*2:%d\tplace:%d\n{eoc}", number->gap.value * 2, number->place);
		}
	}
	return ((ret && ((t_number*)(ret->content))->gap.value) ? ret : NULL);
}

void 			place_min_in_a(t_stack *a, t_stack *b, t_list **cmds)
{

	a->condition = &is_asc;
	ft_printf("min value:%d\n", ((t_number*)(a->control.min->content))->value);
	((t_number*)(a->control.min->content))->index.value = get_index(a, a->control.min);
	if (!get_rotate_control(&((t_number*)(a->control.min->content))->index, a))
		exit(EXIT_FAILURE);
	ft_printf("((t_number*)(a->control.min->content))->index:%d\n", ((t_number*)(a->control.min->content))->index.value);
	prepare_stack(a, ((t_number*)(a->control.min->content))->index.value, cmds, a->control.min->content);
	ft_lstiter(a->list, &print_elem);

	push_b(a, b);
	add_command(cmds, "pb");
	ft_lstiter(a->list, &print_elem);

	((t_number*)(a->control.max->content))->index.value = get_index(a, a->control.max);
	get_rotate_control(&((t_number*)(a->control.max->content))->index, a);
	prepare_stack(a, ((t_number*)(a->control.max->content))->index.value, cmds, a->control.max->content);
	push_a(a, b);
	add_command(cmds, "pa");
	((t_number*)(a->control.min->content))->place = 1;
	((t_number*)(a->control.max->content))->place = 1;
	ft_lstiter(a->list, &print_elem);
	a->condition = &is_asc_1;
	//sleep(2);
}

void 			place_max_in_b(t_stack *a, t_stack *b, t_list **cmds)
{
	//t_list		*list_tmp;
	//int			count = 0;

	//list_tmp = b->list;
	//while (list_tmp && list_tmp != b->control.min && ++count)
	//	list_tmp = list_tmp->next;
	//ft_printf("{green}count:%d\n{eoc}", count);

	b->condition = &is_desc;
	ft_printf("min value:%d\n", ((t_number*)(b->control.min->content))->value);
	((t_number*)(b->control.min->content))->index.value = get_index(b, b->control.min);
	if (!get_rotate_control(&((t_number*)(b->control.min->content))->index, b))
		exit(EXIT_FAILURE);
	//get_gap(b, list_tmp->content, b->control.max, 0);
	ft_printf("((t_number*)(list_tmp->content))->index:%d\n", ((t_number*)(b->control.min->content))->index.value);
	//sleep(2);
	prepare_stack(b, ((t_number*)(b->control.min->content))->index.value, cmds, b->control.min->content);
	ft_lstiter(b->list, &print_elem);
	push_a(a, b);
	add_command(cmds, "pa");

	ft_lstiter(b->list, &print_elem);
	//sleep(2);
	//count = 0;
	//list_tmp = b->list;
	//while (list_tmp && list_tmp != b->control.max && ++count)
	//	list_tmp = list_tmp->next;
	//ft_printf("{green}count:%d\n{eoc}", count);

	//get_gap(b, b->control.max->content, b->control.max, 0);
	((t_number*)(b->control.max->content))->index.value = get_index(b, b->control.max);
	ft_printf("avant:%d\n", ((t_number*)(b->control.max->content))->index.value);
	//sleep(2);
	get_rotate_control(&((t_number*)(b->control.max->content))->index, b);
	ft_printf("apres:%d\n", ((t_number*)(b->control.max->content))->index.value);
	prepare_stack(b, ((t_number*)(b->control.max->content))->index.value + 1, cmds, b->control.max->content);
	push_b(a, b);
	ft_lstiter(b->list, &print_elem);
	//sleep(3);
	add_command(cmds, "pb");
	((t_number*)(b->control.min->content))->place = 1;
	((t_number*)(b->control.max->content))->place = 1;
	ft_lstiter(b->list, &print_elem);
	b->condition = &is_desc_1;
	//sleep(2);
}

t_number 			*sort_in_list(t_stack *stack, t_list **cmds, t_stack *b)
{
	(void)cmds;
	(void)b;
	t_list *smaller;

	smaller = update_all_gap(stack);
	if (smaller)
		((t_number*)(smaller->content))->gap.value *= 2;
	return (smaller ? smaller->content : NULL);
	//while ((smaller = update_all_gap(stack)))
	//{
		ft_printf("{lblue}smaller found\n{eoc}");
		((t_number*)(smaller->content))->gap.value *= 2;
		ft_printf("nombre:%d(index):{green}%d{eoc},gap:{green}%d\t{eoc}\n", ((t_number*)(smaller->content))->value, ((t_number*)(smaller->content))->index.value, ((t_number*)(smaller->content))->gap.value);
		//t_number temp;
		//temp = *(t_number*)(smaller->content);
		//ft_memmove(&temp, smaller->content, sizeof(t_number));
		//ft_printf("{green}index:%d\n{eoc}", temp.index.value);
		//temp.index.ctrl_cmd = get_rotate_ctrl_cmd(&temp.index.value, stack->argc);
		//temp.index.cmd = get_rotate_cmd(temp.index.ctrl_cmd, stack->name);
		//ft_printf("nombre:%d(index):{green}%d{eoc},gap:{green}%d\t{eoc}\n", temp.value, temp.index.value, temp.gap.value);
		//ft_printf("temp.ctrl_cmd:%p\trotate:%p\treverse_rotate:%p\tcmd:%p\n", temp.index.ctrl_cmd, &rotate, &reverse_rotate, temp.index.cmd);
		//ft_printf("smaller.ctrl_cmd:%p\tsmaller.cmd:%p\n",((t_number*)(smaller->content))->index.ctrl_cmd, ((t_number*)(smaller->content))->index.cmd);
		//ft_printf("aVANT PREPARE A\n");
		//	print_stacks(&stack->list, &b->list);
	/*	if (temp.ctrl_cmd == &rotate && ((t_number*)(smaller->content))->ctrl_cmd == &reverse_rotate)
		{
			--temp.index;
			--((t_number*)(smaller->content))->gap;
		}*/

		/*prepare_stack(stack, temp.index.value, cmds, &temp);

		ft_lstiter(stack->list, &print_elem);
		ft_printf("APRE PREPARE A\n");
		while (((t_number*)(smaller->content))->gap.value > 0)
		{
			if (((t_number*)(smaller->content))->gap.value > 1 && ((t_number*)(smaller->content))->gap.ctrl_cmd == &reverse_rotate)
			{
				ft_printf("reverse_rotate\n");
				((t_number*)(smaller->content))->gap.ctrl_cmd(&stack->control, &stack->list,
														((t_number*)(smaller->content))->gap.cmd);
				ft_lstiter(stack->list, &print_elem);
				add_command(cmds, ((t_number*)(smaller->content))->gap.cmd == &do_ra ? "ra" : "rra");
			}
			swap(&stack->control, &stack->list, (!ft_strcmp(stack->name, "stack_a") ? &do_sa : &do_sb));
			add_command(cmds, "sa");
			ft_lstiter(stack->list, &print_elem);
			if (((t_number*)(smaller->content))->gap.value > 2 && ((t_number*)(smaller->content))->gap.ctrl_cmd == &rotate)
			{
				ft_printf("rotate\n");
				((t_number*)(smaller->content))->gap.ctrl_cmd(&stack->control, &stack->list,
														((t_number*)(smaller->content))->gap.cmd);
				add_command(cmds, ((t_number*)(smaller->content))->gap.cmd == &do_ra ? "ra" : "rra");
				ft_lstiter(stack->list, &print_elem);
			}
			((t_number*)(smaller->content))->gap.value -= 2;
		}
		if (smaller)
			((t_number*)(smaller->content))->place = 1;
		//sleep(1);
		ft_printf("APRE while A\n");
		print_stacks(&stack->list, &b->list);
		//printf("boucle:%d\n", i);
		//sleep(1);
	}
	ft_printf("{lblue}smaller no found\n{eoc}");*/
}

int 			max_min_is_placed_in_a(t_control *control)
{
	if (!control)
		return (1);
	if (control->max && control->min &&
		((!control->max->prev && !control->min->next) ||
			control->max->prev == control->min))
		return (1);
	else
		return (0);

}

int 			max_min_is_placed_in_b(t_control *control)
{
	if (!control)
		return (1);
	if (control->max && control->min &&
		((!control->min->prev && !control->max->next) ||
			control->min->prev == control->max))
		return (1);
	else
		return (0);

}

int 			resolve(t_data *data)
{
	int result;

	if (!data)
		return (0);
	ft_printf("{red}PAR LA 1{eoc}\n");
	while (!(result = check_result(data->stack_a.list, data->stack_a.argc)) &&
							data->stack_a.argc > data->stack_b.argc)
	{
		sort_a_firsttime(&data->stack_a, &data->stack_b, &data->cmds);
		ft_printf("{lred}PRINT CONTROL A\n{eoc}");
		print_control(data->stack_a.control);
		ft_printf("{lred}PRINT CONTROL B\n{eoc}");
		print_control(data->stack_b.control);
		ft_printf("{red}a->argc:%d\tb->argc:%d\n{eoc}", data->stack_a.argc, data->stack_b.argc);
		print_stacks(&data->stack_a.list, &data->stack_b.list);
		//sleep(1);
	}
	if (!data->stack_b.argc && result)
	{
		//ft_printf("{cyan}TIER{eoc}\n");
		return (1);
	}
	//int count = 0;
	add_command(&data->cmds, "END");
	ft_printf("DECALAGE:{lgreen}start test\n{eoc}");
	/*int test = get_gap(&data->stack_a, 
						((t_number*)(data->stack_a.list->content))->value,
						(&((t_number*)(data->stack_a.list->content))->ctrl_cmd),
						(&((t_number*)(data->stack_a.list->content))->cmd));
						*/
	t_number *number1 = NULL;
	t_number *number2 = NULL;

	if (!max_min_is_placed_in_a(&data->stack_a.control))
		place_min_in_a(&data->stack_a, &data->stack_b, &data->cmds);
	if (!max_min_is_placed_in_b(&data->stack_b.control))
		place_max_in_b(&data->stack_a, &data->stack_b, &data->cmds);

	while (((number1 = sort_in_list(&data->stack_a, &data->cmds, &data->stack_b)) &&
			(number2 = sort_in_list(&data->stack_b, &data->cmds, &data->stack_a))) || 
			(!number1 && (number2 = sort_in_list(&data->stack_b, &data->cmds, &data->stack_a))) || (number1 && !number2))
	{
		if (number1)
		{
			ft_printf("number 1 => value:%d\n\t\tgap value:%d\tgap ctrl:%p\tgap cmd:%p\n\t\tindex value:%d\tindex ctrl:%p\tindex cmd:%p\n", number1->value, number1->gap.value, number1->gap.ctrl_cmd, number1->gap.cmd, number1->index.value, number1->index.ctrl_cmd, number1->index.cmd);
		}
		if (number2)
			ft_printf("number 2 => value:%d\n\t\tgap value:%d\tgap ctrl:%p\tgap cmd:%p\n\t\tindex value:%d\tindex ctrl:%p\tindex cmd:%p\n", number2->value, number2->gap.value, number2->gap.ctrl_cmd, number2->gap.cmd, number2->index.value, number2->index.ctrl_cmd, number2->index.cmd);
		print_stacks(&data->stack_a.list, &data->stack_b.list);
		//return 1;
		sort_controler(data, number1, number2);
		ft_lstiter(data->stack_a.list, &print_elem);
		write(1, "\n", 1);
		ft_lstiter(data->stack_b.list, &print_elem);
		//return (1);
	}

return (1);


	//		/ \
	//	   / | \
	//	  /  |  \
	//	 /   |   \
	//	/    .    \
	// /___________\
	//

	//return (0);

//FIN DU RESOLVE => OK
	//vide b dans a; => OK
	ft_printf("{red}DEBUG | start sort lvl 2{eoc}\n");
	print_stacks(&data->stack_a.list, &data->stack_b.list);
	int index;
	sleep(10);
	while (data->stack_b.argc)
	{	
		//if (data->stack_b.list)
		if ((index = prepare_b(&data->stack_a, &data->stack_b, &data->cmds)) == -1)
			exit(EXIT_FAILURE);
		//sort_a_secondtime2(&data->stack_a, data->stack_b.list->content, &data->cmds);
		prepare_stack(&data->stack_a, index, &data->cmds, data->stack_b.list->content);

		ft_printf("{cyan}AVANT PUSH_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(data->stack_a.list, &print_elem);
		ft_printf("{green}DEBUG | push a{eoc}\n");
		push_a(&data->stack_a, &data->stack_b);
		add_command(&data->cmds, "pa");
		ft_printf("{cyan}APRES PUSH_A{eoc}\n");
		ft_printf("{magenta}FT_LSTITER A{eoc}\n");
		ft_lstiter(data->stack_a.list, &print_elem);
		ft_printf("{lred}PRINT CONTROL A\n{eoc}");
		print_control(data->stack_a.control);
		ft_printf("{lred}PRINT CONTROL B\n{eoc}");
		print_control(data->stack_b.control);
		print_stacks(&data->stack_a.list, &data->stack_b.list);
		//empty_b(&data->stack_a, &data->stack_b, &data->cmds);
		//sort_a_secondtime(&data->stack_a, &count, &data->cmds);
		sleep(5);
	}
	//t_list *min;
	//align a => ko
	/*
	if (!check_result(data->stack_a.list, data->stack_a.argc))
	{
		min = get_min(data->stack_a.list);
		ft_printf("min value:%d\n", ((t_number*)(min->content))->value);
		int decale = get_gap(&data->stack_a, min->content, data->stack_a.control.min, 0);
		ft_printf("decale:%d\n", decale);
		prepare_stack(&data->stack_a, decale, &data->cmds, min->content);
	}
	*/
	return (1);
}