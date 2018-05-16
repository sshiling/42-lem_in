/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:48:35 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 15:48:37 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_line_to_list_of_args(char *line,
	t_list_of_args **list, char *type)
{
	t_list_of_args	*tmp;

	if (!(*list))
	{
		*list = create_new_list_of_args();
		(*list)->arg = ft_strdup(line);
		(*list)->type = ft_strdup(type);
	}
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_new_list_of_args();
		tmp->next->arg = ft_strdup(line);
		tmp->next->type = ft_strdup(type);
	}
}

void			create_list_of_arguments(int fd, t_list_of_args **new)
{
	char			*line;
	int				check;
	int				key;

	while ((check = get_next_line(fd, &line)))
	{
		if (check == -1)
			return ;
		else if ((key = check_if_comments(line)))
			add_line_to_list_of_args(line, new, "comment");
		else if ((key = check_if_ants(line)))
			g_ants = ft_atoi(line);
		else if ((key = check_if_start_or_end(line)))
			add_line_to_list_of_args(line, new, "command");
		else if ((key = check_if_other_commands(line)))
			add_line_to_list_of_args(line, new, "command");
		else if ((key = check_if_rooms(line, *new)))
			add_line_to_list_of_args(line, new, "room");
		else if ((key = check_if_links(line, *new)))
			add_line_to_list_of_args(line, new, "link");
		ft_strdel(&line);
		if (key == 0)
			break ;
	}
}
