/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:21:01 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/26 21:36:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			add_command(t_list **cmds, char *command_name)
{
	t_command	command;

	if (!cmds || !command_name)
		return ;
	command.name = ft_strdup(command_name);
	ft_lstadd_end(cmds, ft_lstnew(&command, sizeof(command)));
}

void			print_command(t_list *elem)
{

	if (!elem)
		return ;
	ft_dprintf(1, "%s\n", ((t_command*)(elem->content))->name);
}
