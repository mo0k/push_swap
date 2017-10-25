/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:40:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/25 23:27:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void 		init_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->list = NULL;
	stack->argc = 0;
	stack->control.first = NULL;
	stack->control.second = NULL;
	stack->control.last = NULL;
}

static void 		init_data(t_data *data)
{
	if (!data)
		return ;
	init_stack(&data->stack_a);
	init_stack(&data->stack_b);
	data->argc = 0;
	data->fd = 1;
	data->cmds = NULL;
	stock_data(data);
}

static char			**is_multi(char *value)
{
	char separator[5];
	char **split;
	int index;

	if (!value)
		return (NULL);
	separator[0] = '\v';
	separator[1] = '\n';
	separator[2] = '\t';
	separator[3] = ' ';
	separator[4] = 0;
	split = NULL;
	if ((ft_strchr(value, separator[0]) && (index = 0)) ||
		(ft_strchr(value, separator[1]) && (index = 1)) ||
		(ft_strchr(value, separator[2]) && (index = 2)) ||
		(ft_strchr(value, separator[3]) && (index = 3)))
	{
		if (!(split = ft_strsplit(value, separator[index])))
			return (NULL);
	}
	return (split);
}


static int 			tab2len(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (*tab)
	{
		++i;
		++tab;
	}
	return (i);
}

static int 			input(t_data *data, int ac, char **av)
{
	int				i;
	int 			result;
	char 			**split;

	i = 0;
	split = NULL;
	while (i < ac)
	{
		if ((split = is_multi(av[i])) != NULL)
		{
			input(data, tab2len(split), split);
			ft_delstrtab(split);
			i++;
			continue;
		}
		if((result = parse(data, av[i])) == -1)
			return (0);
		else if (!result)
		{
			i++;
			continue ;
		}
		i++;
	}
	return (1);
}

t_list				*get_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (!list->next)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int					init(t_data *d, int ac, char **av)
{
	if (!d || !av || !*av)
		return (0);
	init_data(d);
	if (!input(d, ac -1, av+1))
		return (0);
	d->argc = ft_lstlen(d->stack_a.list);
	d->stack_a.argc = d->argc;
	d->stack_a.control.first = d->stack_a.list;
	d->stack_a.control.second = d->stack_a.list->next;
	d->stack_a.control.last = get_last(d->stack_a.list);
	return (1);
}