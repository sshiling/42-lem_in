/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 23:13:28 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 23:13:30 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			current_depth(t_queue *queue, t_room *map)
{
	while (queue && map && ft_strcmp(map->name, queue->content))
		map = map->next;
	if (map)
		return (map->depth);
	else
		return (0);
}

static t_friend		*find_next_friends_list(char *name, t_room *map)
{
	while (map && ft_strcmp(map->name, name))
		map = map->next;
	if (map)
		return (map->friends);
	else
		return (NULL);
}

void				create_ways_through_queue(t_queue **q,
	t_friend *friend, t_room **map)
{
	t_queue *del;

	while (*q)
	{
		if (friend && friend->room->status == OFF)
		{
			add_friends_to_queue(q, friend->room->name);
			friend->room->depth = current_depth(*q, *map) + 1;
			if (friend->room->type != 'e')
				friend->room->status = ON;
		}
		if (friend && friend->next)
			friend = friend->next;
		else
		{
			del = *q;
			*q = (*q)->next;
			free(del->content);
			free(del);
			if (*q)
				friend = find_next_friends_list((*q)->content, *map);
			while (friend && friend->room->status == ON)
				friend = friend->next;
		}
	}
}

void				find_ways(t_room **map)
{
	t_queue		*queue;
	t_room		*room;
	t_friend	*friend;

	room = *map;
	while (room && room->type != 's')
		room = room->next;
	queue = create_new_queue(room->name);
	friend = room->friends;
	room->status = ON;
	create_ways_through_queue(&queue, friend, map);
}
