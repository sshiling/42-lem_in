/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:51:30 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 16:51:31 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_path_len(t_path *path)
{
	int	i;

	i = 0;
	while (path)
	{
		i++;
		path = path->next;
	}
	return (i);
}

char	*add_to_string(char *to, char *add)
{
	char	*del;

	del = to;
	to = ft_strjoin(to, add);
	ft_strdel(&del);
	return (to);
}

t_room	*find_exit(t_room *map)
{
	while (map && map->type != 'e')
		map = map->next;
	return (map);
}

void	add_friends_to_queue(t_queue **queue, char *name)
{
	t_queue	*tmp;

	tmp = *queue;
	if (!tmp)
	{
		*queue = create_new_queue(name);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_new_queue(name);
}

t_room	*find_room_by_name(t_room *room, char *name)
{
	while (room && ft_strcmp(room->name, name))
		room = room->next;
	return (room);
}
