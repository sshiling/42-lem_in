/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room_to_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:42:36 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 16:10:57 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_last_element_from_map(t_room **map)
{
	t_room	*last;
	t_room	*previous;

	last = *map;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	free_map(&last);
}

int		check_room_for_duplicates(t_room **map)
{
	t_room	*last;
	t_room	*current;

	if (!(*map)->next)
		return (0);
	current = *map;
	last = *map;
	while (last->next)
		last = last->next;
	while (current != last)
	{
		if (!ft_strcmp(current->name, last->name))
		{
			remove_last_element_from_map(map);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int		add_room(t_room **map, char *arg)
{
	char	**elements;
	t_room	*room;

	room = find_place_for_room(map);
	elements = ft_strsplit(arg, ' ');
	room->name = ft_strdup(elements[0]);
	room->type = room->type == '*' ? 'p' : room->type;
	if (!check_int(elements[1], 0) || !check_int(elements[2], 0))
		return (0);
	room->x = ft_atoi(elements[1]);
	room->y = ft_atoi(elements[2]);
	free_arrays(&elements);
	if (check_room_for_duplicates(map))
		return (0);
	return (1);
}
