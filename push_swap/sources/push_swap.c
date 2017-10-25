/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/25 23:35:52 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <string.h>

static int		exit_error(t_data *data)
{
	write(2, "Error\n", 6);
	clear(data);
	return (EXIT_FAILURE);
}

int				check_result(t_list *stack, int nbr_arg)
{
	t_list			*next;
	t_number		*a;
	t_number		*b;
	int				i;

	if (!stack)
		return (0);
	i = 1;
	while (stack)
	{
		if (!(next = stack->next))
			break;
		i++;
		a = (t_number*)(stack->content);
		b = (t_number*)(next->content);
		if (a->value > b->value)
		{
			return (0);
		}
		stack = stack->next;
	}
	return ((i == nbr_arg) ? 1 : 0);
}

void			empty_b(t_stack *a, t_stack *b)
{
	//printf("DEBUG | start empty_stack_b\n");
	t_number *first;
	t_number *second;
	t_number *last;

	first = b->control.first ? b->control.first->content : NULL;
	second = b->control.second ? b->control.second->content : NULL;
	last = b->control.last ? b->control.last->content : NULL;
	ft_printf("first(%p)\tsecond(%p)\n", first, second);
	if (first && second && first->value > second->value)
	{
		//printf("DEBUG | push\n");
		push_a(a, b);
	}
	else if (first && second && first->value < second->value)
	{
		//printf("DEBUG | swap & push\n");
		swap(b, do_sb);
		push_a(a, b);
	}
	else if (first && !second && b->argc == 1)
		push_a(a, b);
}

void 			sort_b(t_stack *b)
{
	ft_printf("start sort b\n");
	print_control(b->control);
	t_number *first;
	t_number *second;
	t_number *last;

	first = b->control.first ? b->control.first->content : NULL;
	second = b->control.second ? b->control.second->content : NULL;
	last = b->control.last ? b->control.last->content : NULL;
	if (last && first && first->value < last->value)
	{
		rotate(b, do_rb);
	}
	else if (last && second && second->value < last->value)
	{
		swap(b, do_sb);
		rotate(b, do_rb);
	}
	else if (first && second && first->value < second->value)
	{
		swap(b, do_sb);
	}
}

void 			sort_a_firsttime(t_stack *a, t_stack *b)
{
	print_control(a->control);
	t_number *first;
	t_number *second;
	t_number *last;

	first = a->control.first ? a->control.first->content : NULL;
	second = a->control.second ? a->control.second->content : NULL;
	last = a->control.last ? a->control.last->content : NULL;
	if (last && first && first->value > last->value)
	{
		rotate(a, do_ra);
	}
	else if (last && second && second->value > last->value)
	{
		swap(a, do_sa);
		rotate(a, do_ra);
	}
	else if (first && second && first->value < second->value)
	{
		push_b(a, b);
		sort_b(b);
	}
	else if (first && second && first->value > second->value)
	{
		swap(a, do_sa);
	}
}
/*
int 			init_number(t_stack *stack, t_number *first, t_number *second, t_number *last)
{
	if (!first || !second || !last)
		return (0);
	first = stack->control.first ? stack->control.first->content : NULL;
	second = stack->control.second ? stack->control.second->content : NULL;
	last = stack->control.last ? stack->control.last->content : NULL;
	return (1);
}*/



void 			sort_a_secondtime(t_stack *a, int *count)
{
	ft_printf("{red}start sort_a_secondtime{eoc}\n");
	print_control(a->control);
	t_number *first;
	t_number *second;
	t_number *last;

	first = a->control.first ? a->control.first->content : NULL;
	second = a->control.second ? a->control.second->content : NULL;
	last = a->control.last ? a->control.last->content : NULL;
	ft_printf("DEBUG | 1 first(%p):%d\tsecond(%p):%d\n", first, first->value ,second, second->value);
	//if (first && second && first->value > second->value)
	//{
		while (first && second && first->value > second->value)
		{
			ft_printf("DEBUG | 2 first(%p):%d\tsecond(%p):%d\n", first, first->value ,second, second->value);
			swap(a, do_sa);
			print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
			if (!check_result(a->list, a->argc))
			{
				rotate(a, do_ra);
				print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
				++(*count);

				ft_printf("count:%d\n", *count);
				//sort_a_secondtime(a, count);
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
		ft_printf("DEBUG | 1 first(%p):%d\tlast(%p):%d\n", first, first->value ,last, last->value);
		while (first && last && first->value < last->value && *count)
		{
			ft_printf("DEBUG | 2 first(%p):%d\tlast(%p):%d\n", first, first->value ,last, last->value);
			reverse_rotate(a, do_rra);
				print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
			swap(a, do_sa);
				print_stacks(&a->list, &stock_data(NULL)->stack_b.list);
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
	ft_printf("{blue}count:%d{eoc}\n", *count);
}

static int 			resolve(t_data *data)
{
	if (!data)
		return (0);
	ft_printf("{red}PAR LA 1{eoc}\n");
	while (!check_result(data->stack_a.list, data->stack_a.argc))
	{
		sort_a_firsttime(&data->stack_a, &data->stack_b);
		print_stacks(&data->stack_a.list, &data->stack_b.list);
	}
	if (!data->stack_b.argc)
	{
		ft_printf("{cyan}TIER{eoc}\n");
		return (1);
	}
	int count = 0;
	while (data->stack_b.argc)
	{
		empty_b(&data->stack_a, &data->stack_b);
		sort_a_secondtime(&data->stack_a, &count);
	}
	return (1);
}
int				main(int ac, char **av)
{
	t_data			data;
	int 			ret;

	if (ac < 2 || !init(&data, ac, av))
		return (exit_error(&data));
	ret = 0;
	resolve(&data);
	print_stacks(&data.stack_a.list, &data.stack_b.list);
	clear(&data);
	return (0);
}