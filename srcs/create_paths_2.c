/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:26:41 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/10 13:26:43 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			check_each_path(t_list_of_paths *current,
	t_list_of_paths **list)
{
	t_list_of_paths	*previous;

	if (current->path->room->type == 's')
		return ;
	previous = *list;
	if (previous == current)
	{
		free_all_paths((*list)->path);
		free_element_in_list_of_paths(current, list);
	}
	while (previous->next != current)
		previous = previous->next;
	free_all_paths(current->path);
	free_element_in_list_of_paths(current, list);
	previous->next = current->next;
}

int				check_paths_for_start_and_exit(t_list_of_paths **list)
{
	t_list_of_paths	*tmp_list;

	tmp_list = *list;
	while (tmp_list)
	{
		check_each_path(tmp_list, list);
		tmp_list = tmp_list->next;
	}
	if (!(*list))
		return (0);
	return (1);
}

void			create_first_path_in_list(t_room *start, t_room *add,
	int path_id, t_list_of_paths **list_of_paths)
{
	t_path	*path;

	path = create_new_path();
	path->room = add;
	path->next = create_new_path();
	path->next->room = start;
	path->id = path_id;
	path->next->id = path_id;
	(*list_of_paths)->path = path;
}

void			add_new_list_to_list_of_paths(t_room *start, t_room *add,
	int path_id, t_list_of_paths **list_of_paths)
{
	t_list_of_paths	*tmp_list;

	if (!(*list_of_paths)->path)
	{
		create_first_path_in_list(start, add, path_id, list_of_paths);
		return ;
	}
	tmp_list = *list_of_paths;
	while (tmp_list->next && tmp_list->path && tmp_list->path->id != path_id)
		tmp_list = tmp_list->next;
	if (!tmp_list->next)
	{
		tmp_list->next = create_new_list_of_paths();
		tmp_list->next->path = create_new_path();
		tmp_list->next->path->room = add;
		tmp_list->next->path->id = path_id;
		tmp_list->next->path->next = create_new_path();
		tmp_list->next->path->next->room = start;
		tmp_list->next->path->next->id = path_id;
		return ;
	}
}
