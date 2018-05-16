/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:52:11 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 16:52:13 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		move_all_at_the_same_time(t_ants *ant_list, t_list_of_paths *path_list)
{
	char		*result;
	t_path		*tmp_path;

	result = ft_strnew(1);
	tmp_path = NULL;
	while (path_list)
	{
		if (path_list->path->room && path_list->path->room->type == 's' &&
			path_list->path->next->room->type == 'e')
			tmp_path = path_list->path->next;
		path_list = path_list->next;
	}
	if (!tmp_path)
	{
		free(result);
		return (0);
	}
	while (ant_list)
	{
		result = save_result(result, ant_list, tmp_path);
		ant_list = ant_list->next;
	}
	ft_printf("%s\n", result);
	free(result);
	return (1);
}

void	include_ant_into_queue(t_ants **ants, t_list_of_paths **paths)
{
	t_ants	*current_ant;
	t_path	*path;

	current_ant = *ants;
	path = choose_shortest_path(paths);
	path->ant_num = current_ant->ant_num;
	current_ant->path = path;
	current_ant->queue = ON;
}

void	create_ants_queue(t_ants **ants, t_list_of_paths **list_of_paths)
{
	t_ants	*list_of_ants;

	list_of_ants = *ants;
	while (list_of_ants)
	{
		if (list_of_ants->queue == OFF)
			include_ant_into_queue(&list_of_ants, list_of_paths);
		else
			list_of_ants = list_of_ants->next;
	}
}

void	del_ant_from_list_of_ants(t_ants **list_of_ants, t_ants *current)
{
	t_ants *del;
	t_ants *previous;

	del = *list_of_ants;
	previous = NULL;
	while (del->ant_num != current->ant_num)
	{
		previous = del;
		del = del->next;
	}
	if (del == *list_of_ants && del->next == NULL)
		free_one_ant(list_of_ants);
	else if (del->next == NULL)
		free_one_ant(&del);
	else if (!previous)
	{
		*list_of_ants = (*list_of_ants)->next;
		free_one_ant(&del);
	}
	else
	{
		previous->next = del->next;
		free_one_ant(&del);
	}
}

char	*move_one_ant(t_ants **ant, char *res)
{
	(*ant)->path->ant_num = 0;
	(*ant)->path = (*ant)->path->next;
	(*ant)->path->ant_num = (*ant)->ant_num;
	if ((*ant)->path->room && (*ant)->path->room->type != 's')
		res = save_result(res, *ant, (*ant)->path);
	return (res);
}
