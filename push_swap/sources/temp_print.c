/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:19:35 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/12 12:29:23 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		print_control(t_control control)
{
	ft_printf("first  => %p\n", control.first);
	if (control.first)
		ft_printf("first  => %d\n", ((t_number*)(control.first->content))->value);
	ft_printf("second => %p\n", control.second);
	if (control.second)
		ft_printf("second  => %d\n", ((t_number*)(control.second->content))->value);
	ft_printf("last   => %p\n", control.last);
	if (control.last)
		ft_printf("last  => %d\n", ((t_number*)(control.last->content))->value);
	ft_printf("min => %p\n", control.min);
	ft_printf("max => %p\n", control.max);
}

void				print_elem(t_list *elem)
{
		ft_printf("maillon de stack_a(%p):%d\tprev(%p)\tnext(%p)\n", elem,
			((t_number*)(elem->content))->value, elem->prev, elem->next);
}

static void	print_stacks_header(int fd)
{
	ft_dprintf(fd, "\t{cyan} ______________ \t ______________\n"		\
		"\t|      a       |\t|      b       |\n"		\
		"\t|______________|\t|______________|{eoc}\n"	\
		"\t|              |\t|              |\n");
}


void		print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_number	*a;
	t_number	*b;
	t_list		*ptr_stack_a;
	t_list		*ptr_stack_b;
	int			i;
	int			fd;

	if (!stack_a || !stack_b)
		return ;
	i = 0;
	ptr_stack_a = *stack_a;
	ptr_stack_b = *stack_b;
	fd = stock_data(NULL)->fd;
	ft_dprintf(fd, "\nEtat des piles:\n");
	while (ptr_stack_a || ptr_stack_b)
	{
		if (!i++)
			print_stacks_header(fd);
		a = (ptr_stack_a) ? (t_number*)(ptr_stack_a->content) : 0;
		b = (ptr_stack_b) ? (t_number*)(ptr_stack_b->content) : 0;
		if (!a)
			ft_dprintf(fd, "\t|      %-8c|\t|      %-8d|\n", ' ', b->value);
		else if (!b)
			ft_dprintf(fd, "\t|      %-8d|\t|      %-8c|\n", a->value, ' ');
		else
			ft_dprintf(fd, "\t|      %-8d|\t|      %-8d|\n", a->value, b->value);
		ptr_stack_a = (ptr_stack_a) ? ptr_stack_a->next : 0;
		ptr_stack_b = (ptr_stack_b) ? ptr_stack_b->next : 0;
		if (!ptr_stack_a && !ptr_stack_b)
			ft_dprintf(fd, "\t|______________|\t|______________|\n\n");
	}
}
