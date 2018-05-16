/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_friends_connections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:20:39 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 22:20:41 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_new_friends(t_room **current, t_room **map, char *name)
{
	t_room		*tmp_map;
	t_friend	*tmp_friend;

	tmp_map = *map;
	if (!(*current)->friends)
		(*current)->friends = create_new_friend();
	tmp_friend = (*current)->friends;
	while (tmp_friend->next)
		tmp_friend = tmp_friend->next;
	if (tmp_friend->room)
	{
		tmp_friend->next = create_new_friend();
		tmp_friend = tmp_friend->next;
	}
	while (tmp_map && ft_strcmp(tmp_map->name, name))
		tmp_map = tmp_map->next;
	if (tmp_map)
		tmp_friend->room = tmp_map;
}

void			add_friends_list(t_room **map, t_cnct *cncntns)
{
	t_room	*tmp_room;
	t_cnct	*tmp_cnct;

	tmp_cnct = cncntns;
	while (tmp_cnct)
	{
		tmp_room = *map;
		if (!ft_strcmp(cncntns->room_1, cncntns->room_2))
			return ;
		while (tmp_room)
		{
			if (!ft_strcmp(tmp_cnct->room_1, tmp_room->name))
				add_new_friends(&tmp_room, map, tmp_cnct->room_2);
			if (!ft_strcmp(tmp_cnct->room_2, tmp_room->name))
				add_new_friends(&tmp_room, map, tmp_cnct->room_1);
			tmp_room = tmp_room->next;
		}
		tmp_cnct = tmp_cnct->next;
	}
}
