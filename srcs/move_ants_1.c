/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:51:59 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 16:52:01 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*choose_shortest_path(t_list_of_paths **paths)
{
	t_list_of_paths	*list_of_paths;
	t_list_of_paths	*pointer_to_shortest;
	t_path			*new;

	list_of_paths = *paths;
	pointer_to_shortest = *paths;
	while (list_of_paths->next)
	{
		if (find_path_len(list_of_paths->path) >
			find_path_len(list_of_paths->next->path))
			pointer_to_shortest = list_of_paths->next;
		list_of_paths = list_of_paths->next;
	}
	new = create_new_path();
	new->id = pointer_to_shortest->path->id;
	new->next = pointer_to_shortest->path;
	pointer_to_shortest->path = new;
	return (pointer_to_shortest->path->next);
}

void	move_ants(t_ants **list_of_ants)
{
	t_ants	*tmp_ant;
	char	*res;

	res = ft_strnew(1);
	tmp_ant = *list_of_ants;
	while (tmp_ant)
	{
		if (tmp_ant->path->room && tmp_ant->path->room->type == 'e')
			del_ant_from_list_of_ants(list_of_ants, tmp_ant);
		else
			res = move_one_ant(&tmp_ant, res);
		tmp_ant = tmp_ant->next;
	}
	ft_printf("%s", res);
	free(res);
}

void	create_and_print_result(t_list_of_args *list_of_args,
	t_list_of_paths *list_of_paths)
{
	t_ants		*list_of_ants;

	print_list_of_args(list_of_args);
	if (g_path_print == ON)
		print_paths_and_len(list_of_paths);
	list_of_ants = create_list_of_ants();
	if (move_all_at_the_same_time(list_of_ants, list_of_paths))
	{
		free_list_of_ants(&list_of_ants);
	}
	else
	{
		create_ants_queue(&list_of_ants, &list_of_paths);
		while (list_of_ants)
		{
			move_ants(&list_of_ants);
			if (list_of_ants)
				ft_printf("\n");
		}
	}
}
