/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structures_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:23:01 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 17:23:03 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_of_args		*create_new_list_of_args(void)
{
	t_list_of_args	*list;

	list = (t_list_of_args*)malloc(sizeof(t_list_of_args));
	list->arg = NULL;
	list->type = NULL;
	list->next = NULL;
	return (list);
}

t_room				*create_new_room(void)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = NULL;
	room->type = '*';
	room->x = -1;
	room->y = -1;
	room->status = OFF;
	room->path = OFF;
	room->depth = 0;
	room->ant = 0;
	room->friends = NULL;
	room->next = NULL;
	return (room);
}

t_cnct				*create_new_cnctn(void)
{
	t_cnct	*connection;

	connection = (t_cnct*)malloc(sizeof(t_cnct));
	connection->room_1 = NULL;
	connection->room_2 = NULL;
	connection->next = NULL;
	return (connection);
}

t_friend			*create_new_friend(void)
{
	t_friend	*friend;

	friend = (t_friend*)malloc(sizeof(t_friend));
	friend->room = NULL;
	friend->next = NULL;
	return (friend);
}

t_list_of_paths		*create_new_list_of_paths(void)
{
	t_list_of_paths	*new;

	new = (t_list_of_paths*)malloc(sizeof(t_list_of_paths));
	new->path = NULL;
	new->next = NULL;
	return (new);
}
