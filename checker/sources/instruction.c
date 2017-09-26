/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:17:33 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/27 01:45:13 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

t_instruction		*get_tab_instruction(t_instruction *instruction)
{
	static t_instruction	tab[NBR_INSTRUCTIONS] = {
		{"sa", do_sa},
		{"sb", do_sb},
		{"ss", do_ss},
		{"pa", do_pa},
		{"pb", do_pb},
		{"ra", do_ra},
		{"rb", do_rb},
		{"rr", do_rr},
		{"rra", do_rra},
		{"rrb", do_rrb},
		{"rrr", do_rrr},
		{"print", &print_stacks}
	};

	instruction = tab;
	return (instruction);
}

int			find_instruction(t_instruction *instruction, char *cmd)
{
	int 					i;

	i = 0;
	while (i < NBR_INSTRUCTIONS)
	{
		if (!ft_strcmp(cmd, instruction[i].name))
			return (i);
		++i;
	}
	return (-1);
}
