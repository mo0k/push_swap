/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:19:35 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/27 01:45:14 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				del_number(void *content, size_t size)
{
	(void)size;
	free(content);
	content = NULL;
}

void		print_prog_header(void)
{
	ft_printf("{lblue} _______________________________________________________\n");
	ft_printf("|							|\n");
	ft_printf("|		{eoc}{white}PUSH_SWAP ------ CHECKER{eoc}{lblue}		|\n");
	ft_printf("|							|\n");
	ft_printf("|_______________________________________________________|{eoc}\n\n");
}

static void	print_stacks_header(void)
{
	ft_printf("\t{cyan} ______________ \t ______________\n" \
				"\t|      a       |\t|      b       |\n" \
				"\t|______________|\t|______________|{eoc}\n" \
				"\t|              |\t|              |\n");
}


void		print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_number	*a;
	t_number	*b;
	t_list		*ptr_stack_a;
	t_list		*ptr_stack_b;
	int			i;

	if (!stack_a || !stack_b)
		return ;
	i = 0;
	ptr_stack_a = *stack_a;
	ptr_stack_b = *stack_b;
	ft_printf("\nEtat des piles:\n");
	while (ptr_stack_a || ptr_stack_b)
	{
		if (!i++)
			print_stacks_header();
		a = (ptr_stack_a) ? (t_number*)(ptr_stack_a->content) : 0;
		b = (ptr_stack_b) ? (t_number*)(ptr_stack_b->content) : 0;
		if (!a)
			ft_printf("\t|      %-8c|\t|      %-8d|\n", ' ', b->value);
		else if (!b)
			ft_printf("\t|      %-8d|\t|      %-8c|\n", a->value, ' ');
		else
			ft_printf("\t|      %-8d|\t|      %-8d|\n", a->value, b->value);
		ptr_stack_a = (ptr_stack_a) ? ptr_stack_a->next : 0;
		ptr_stack_b = (ptr_stack_b) ? ptr_stack_b->next : 0;
		if (!ptr_stack_a && !ptr_stack_b)
			ft_printf("\t|______________|\t|______________|\n\n");
	}
}
