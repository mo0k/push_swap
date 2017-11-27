/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:19:35 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/27 21:54:45 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				del_number(void *content, size_t size)
{
	(void)size;
	free(content);
	content = NULL;
}
void				print_elem(t_list *elem)
{
		printf("maillon de stack_a(%p):%d\tprev(%p)\tnext(%p)\n", elem, ((t_number*)(elem->content))->value, elem->prev, elem->next);
}

void		print_help(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	ft_printf("\n{lgreen}HELP{eoc}:\n\n" \
		" {green}I{eoc} Options :\n\t-v : verbose\n" \
		"\t-f : Copy output to file named \"log\" in curdir\n" \
		"\t-c : Color\n" \
		"\t-r : Display stacks at the end of execution\n\n" \
		" {green}II{eoc} Instruction:\n\tsa  => swap a\n"
		"\tsb  => swap b\n"
		"\tss  => swap a & swap b\n"
		"\tpa  => push a\n"
		"\tpb  => push b\n"
		"\tra  => rotate a\n"
		"\trb  => rotate b\n"
		"\trr  => rotate a & rotate b\n"
		"\trra  => reverse rotate a\n"
		"\trrb  => reverse rotate a\n"
		"\trrr  => reverse rotate a & reverse rotate b\n\n");
}

void		print_prog_header(t_uchar color, int fd)
{
	if (color)
	{
		ft_dprintf(fd, "{lblue} _______________________________________________________\n");
		ft_dprintf(fd, "|							|\n");
		ft_dprintf(fd, "|		{eoc}{white}PUSH_SWAP ------ CHECKER{eoc}{lblue}		|\n");
		ft_dprintf(fd, "|							|\n");
		ft_dprintf(fd, "|_______________________________________________________|{eoc}\n\n");
	}
	else
	{
		ft_dprintf(fd, " _______________________________________________________\n");
		ft_dprintf(fd, "|							|\n");
		ft_dprintf(fd, "|		PUSH_SWAP ------ CHECKER		|\n");
		ft_dprintf(fd, "|							|\n");
		ft_dprintf(fd, "|_______________________________________________________|\n\n");
	}
}

static void	print_stacks_header(t_uchar color, int fd)
{
	if (color)
		ft_dprintf(fd, "\t{cyan} ______________ \t ______________\n"		\
				"\t|    PILE A    |\t|    PILE B    |\n"		\
				"\t|______________|\t|______________|{eoc}\n"	\
				"\t|              |\t|              |\n");
	else
		ft_dprintf(fd, "\t ______________ \t ______________\n"		\
				"\t|    PILE A    |\t|    PILE B    |\n"		\
				"\t|______________|\t|______________|\n"	\
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
			print_stacks_header(stock_data(NULL)->options.color, fd);
		a = (ptr_stack_a) ? (t_number*)(ptr_stack_a->content) : 0;
		b = (ptr_stack_b) ? (t_number*)(ptr_stack_b->content) : 0;
		if (!a)
			ft_dprintf(fd, "\t|%12c  |\t|%12d  |\n", ' ', b->value);
		else if (!b)
			ft_dprintf(fd, "\t|%12d  |\t|%12c  |\n", a->value, ' ');
		else
			ft_dprintf(fd, "\t|%12d  |\t|%12d  |\n", a->value, b->value);
		ptr_stack_a = (ptr_stack_a) ? ptr_stack_a->next : 0;
		ptr_stack_b = (ptr_stack_b) ? ptr_stack_b->next : 0;
		if (!ptr_stack_a && !ptr_stack_b)
			ft_dprintf(fd, "\t|______________|\t|______________|\n\n");
	}
}
