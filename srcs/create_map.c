/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:06:54 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 21:06:55 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_invalid_elements_from_map(t_room **map)
{
	t_room	*previous;
	t_room	*del;

	if (!(*map)->name)
	{
		free_map(map);
		return ;
	}
	del = *map;
	while (del)
	{
		if (!del->name)
		{
			previous->next = del->next;
			free_map(&del);
			return ;
		}
		previous = del;
		del = del->next;
	}
}

int		check_if_links(char *line, t_list_of_args *list)
{
	char	**elements;

	if (!ft_strchr(line, '-') || g_ants < 0 ||
		ft_strlen(line) < 3 || ft_strchr(line, ' ') || g_check == 0)
		return (0);
	elements = ft_strsplit(line, '-');
	if (find_split_len(elements, 2))
		return (0);
	if (!ft_strcmp(elements[0], elements[1]) ||
		!check_if_room_exist(list, elements[0]) ||
		!check_if_room_exist(list, elements[1]))
	{
		free_arrays(&elements);
		return (0);
	}
	free_arrays(&elements);
	g_check = 2;
	return (1);
}

int		add_link(t_cnct **cnctns, char *arg)
{
	t_cnct	*tmp;
	char	**elements;

	if (!ft_strchr(arg, '-'))
		return (0);
	if (!(*cnctns))
		*cnctns = create_new_cnctn();
	tmp = *cnctns;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->room_1)
	{
		tmp->next = create_new_cnctn();
		tmp = tmp->next;
	}
	elements = ft_strsplit(arg, '-');
	tmp->room_1 = ft_strdup(elements[0]);
	tmp->room_2 = ft_strdup(elements[1]);
	free_arrays(&elements);
	return (1);
}

void	check_for_start_and_end(t_room *map)
{
	int		i;

	i = 0;
	while (map)
	{
		if (map->type == 's' || map->type == 'e')
			i++;
		map = map->next;
	}
	if (i != 2)
		ft_exit("Map without entrance and/or exit or rooms duplicates");
}

void	create_map(t_room **map, t_list_of_args *list)
{
	t_cnct	*connections;
	int		key;

	connections = NULL;
	while (list)
	{
		key = 0;
		if (!(ft_strcmp(list->type, "comment")))
			key = 1;
		else if (!(ft_strcmp(list->type, "command")))
			key = add_room_type(map, list->arg);
		else if (!(ft_strcmp(list->type, "room")))
			key = add_room(map, list->arg);
		else if (!(ft_strcmp(list->type, "link")))
			key = add_link(&connections, list->arg);
		if (key == 0)
			break ;
		list = list->next;
	}
	if (!(*map) || !(*map)->name)
		return ;
	remove_invalid_elements_from_map(map);
	check_for_start_and_end(*map);
	add_friends_list(map, connections);
	free_connections(&connections);
}
