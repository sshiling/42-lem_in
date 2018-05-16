/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:22:53 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/10 13:22:55 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_friend		*find_shortest_path(t_room *room)
{
	t_friend	*friend;
	t_friend	*result;

	friend = room->friends;
	while (friend)
	{
		if (friend->room->type == 's')
			return (friend);
		friend = friend->next;
	}
	friend = room->friends;
	while (friend && friend->room->status == OFF)
		friend = friend->next;
	if (!friend)
		return (NULL);
	result = friend;
	while (friend->next)
	{
		if (friend->next->room->depth < friend->room->depth
			&& friend->next->room->status == ON)
			result = friend->next;
		friend = friend->next;
	}
	return (result);
}

void			continue_paths_in_list_of_paths(t_room *add,
	t_list_of_paths **list_of_paths)
{
	t_path				*path;
	int					path_id;
	t_list_of_paths		*tmp_list;

	tmp_list = *list_of_paths;
	while (tmp_list && tmp_list->path->id != add->path)
		tmp_list = tmp_list->next;
	path_id = tmp_list->path->id;
	path = create_new_path();
	path->room = add;
	path->id = path_id;
	path->next = tmp_list->path;
	tmp_list->path = path;
}

void			create_first_part_of_list_of_paths(t_queue **queue,
	t_room **room, t_list_of_paths **list_of_paths)
{
	t_friend	*friend;
	int			i;

	i = 0;
	while ((friend = find_shortest_path(*room)))
	{
		friend->room->path = i;
		if (i == 0 && friend->room->type == 's')
		{
			add_new_list_to_list_of_paths(*room, friend->room,
				i, list_of_paths);
			return ;
		}
		if (friend->room->type != 's')
			friend->room->status = OFF;
		add_new_list_to_list_of_paths(*room, friend->room, i, list_of_paths);
		add_friends_to_queue(queue, friend->room->name);
		i++;
	}
}

void			del_first_element_in_queue(t_queue **queue)
{
	t_queue *del;

	del = *queue;
	*queue = (*queue)->next;
	free(del->content);
	free(del);
}

void			create_paths(t_room **map, t_list_of_paths **list_of_paths)
{
	t_queue		*queue;
	t_room		*room;
	t_friend	*friend;

	queue = NULL;
	room = find_exit(*map);
	create_first_part_of_list_of_paths(&queue, &room, list_of_paths);
	while (queue)
	{
		room = find_room_by_name(*map, queue->content);
		friend = find_shortest_path(room);
		if (friend && friend->room)
		{
			if (friend->room->type != 's')
				add_friends_to_queue(&queue, friend->room->name);
			friend->room->path = room->path;
			continue_paths_in_list_of_paths(friend->room, list_of_paths);
			if (friend->room->type != 's')
				friend->room->status = OFF;
		}
		del_first_element_in_queue(&queue);
	}
}
