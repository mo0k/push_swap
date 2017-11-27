/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:19:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/26 23:44:18 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int 			resolve_shortlist(t_data *data)
{
	int 		result;
	t_list 		*min_action;

	if (!data)
		return (0);
	while (!(result = check_result(data->stack_a.list, data->stack_a.argc)))
		sort_a_firsttime(&data->stack_a, &data->stack_b);
	if (!data->stack_b.argc && result)
		return (1);
	while (data->stack_b.list)
	{
		min_action = update_all_index_b(&data->stack_a, &data->stack_b);
		sort_controler(&data->stack_a, &data->stack_b);
		push_a(&data->stack_a, &data->stack_b);
		write(1, "pa\n", 3);
		data->stack_a.action.value = -1;
		data->stack_b.action.value = -1;
	}
	if (!check_result(data->stack_a.list, data->stack_a.argc))
	{
		data->stack_a.action.value = find_index(data->stack_a.list, data->stack_a.control.min);
		get_rotate_control(&data->stack_a.action, &data->stack_a);
		prepare_stack(&data->stack_a, data->stack_a.action.value);
	}
	return (1);
}

int 				resolve_longlist(t_data *data)
{
	t_list *min_action;

	if (!data)
		exit(EXIT_FAILURE);
	while (data->stack_a.list)
	{
		//print_stacks(&data->stack_a.list, &data->stack_b.list);
		min_action = update_all_index_a(&data->stack_a, &data->stack_b);
		//ft_printf("select number is:%d\n\n", ((t_number*)(min_action->content))->value);
		sort_controler(&data->stack_a, &data->stack_b);
		push_b(&data->stack_a, &data->stack_b);
		write(1, "pb\n", 3);
		data->stack_a.action.value = -1;
		data->stack_b.action.value = -1;
	}
	data->stack_b.action.value = find_index(data->stack_b.list, data->stack_b.control.max);
	get_rotate_control(&data->stack_b.action, &data->stack_b);
	prepare_stack(&data->stack_b, data->stack_b.action.value);
	while (data->stack_b.list)
	{
		push_a(&data->stack_a, &data->stack_b);
		write(1, "pa\n", 3);
	}
	return (1);
}