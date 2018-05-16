/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:28:24 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 17:28:27 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_arrays(char ***elements)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *elements;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	*elements = NULL;
}

void	free_list_of_args(t_list_of_args **list)
{
	t_list_of_args	*del;
	t_list_of_args	*tmp;

	tmp = *list;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del->type);
		free(del->arg);
		free(del);
	}
	*list = NULL;
}

void	free_connections(t_cnct **connections)
{
	t_cnct	*tmp;
	t_cnct	*del;

	tmp = *connections;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del->room_1);
		free(del->room_2);
		free(del);
	}
	*connections = NULL;
}

void	free_friends(t_friend **friend)
{
	t_friend	*del;
	t_friend	*tmp;

	tmp = *friend;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*friend = NULL;
}

void	free_map(t_room **map)
{
	t_room *tmp_room;
	t_room *del_room;

	tmp_room = *map;
	while (tmp_room)
	{
		del_room = tmp_room;
		tmp_room = tmp_room->next;
		if (del_room->name)
			free(del_room->name);
		if (del_room->friends)
			free_friends(&del_room->friends);
		free(del_room);
	}
	*map = NULL;
}
