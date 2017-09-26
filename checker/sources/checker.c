/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:10:39 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/26 23:40:57 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <string.h>

static int exit_error(void)
{
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

static int		init(t_data *data, int ac, char **av)
{
	int				i;
	t_number		number;

	if (!data || !av || !*av)
		return (0);
	data->instruction = get_tab_instruction(data->instruction);
	data->stack_a = NULL;
	data->stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		//check av[i] si integer correct
		number.value = ft_atoi(av[i++]);
		ft_lstadd_end(&data->stack_a, ft_lstnew(&number, sizeof(number)));
	}
	return (1);
}
int				main(int ac, char **av)
{
	t_data			data;
	char			*readline;
	int				index;

	if (ac < 2 || !init(&data, ac, av))
		return (exit_error());
	print_prog_header();
	while (1)
	{
		if (ft_printf("Instruction: ") && get_next_line(0, &readline))
		{
			if ((index = find_instruction(data.instruction, readline)) == -1)
				ft_dprintf(2, "{red}%s{eoc} isn't an instruction\n", readline);
			else
				data.instruction[index].pfunc(data.stack_a, data.stack_b);
		}
		free(readline);
	}
	//free *list a & b
	return (0);
}