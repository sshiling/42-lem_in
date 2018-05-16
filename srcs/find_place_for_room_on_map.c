/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_for_room_on_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:14:03 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 16:14:08 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		set_room_type(t_room **map, char room_type)
{
	t_room	*tmp;

	if (!(*map))
		*map = create_new_room();
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->x != -1)
	{
		tmp->next = create_new_room();
		tmp = tmp->next;
	}
	tmp->type = room_type;
	return (1);
}

int		add_room_type(t_room **map, char *arg)
{
	if (!(ft_strcmp(arg, "##start")))
		return (set_room_type(map, 's'));
	if (!(ft_strcmp(arg, "##end")))
		return (set_room_type(map, 'e'));
	return (1);
}

t_room	*find_place_for_room(t_room **map)
{
	t_room	*room;

	if (!(*map))
		*map = create_new_room();
	room = *map;
	while (room->next)
		room = room->next;
	if (room->x != -1)
	{
		room->next = create_new_room();
		room = room->next;
	}
	return (room);
}
