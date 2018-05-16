/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:14:01 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 20:14:03 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_element_in_list_of_paths(t_list_of_paths *current,
	t_list_of_paths **list)
{
	t_list_of_paths	*del;
	t_list_of_paths	*previous;

	del = *list;
	previous = *list;
	while (del != current)
	{
		previous = del;
		del = del->next;
	}
	previous->next = del->next;
	free(del);
}

void	free_all_paths(t_path *path)
{
	t_path		*temp;

	while (path)
	{
		temp = path;
		path = path->next;
		free(temp);
	}
}

void	free_list_of_paths(t_list_of_paths **list)
{
	t_list_of_paths	*tmp_list;
	t_list_of_paths	*del_list;

	tmp_list = *list;
	while (tmp_list)
	{
		del_list = tmp_list;
		tmp_list = tmp_list->next;
		free_all_paths(del_list->path);
		free(del_list);
	}
	*list = NULL;
}

void	free_one_ant(t_ants **ant)
{
	t_ants	*del;

	del = *ant;
	*ant = (*ant)->next;
	free(del);
}

void	free_list_of_ants(t_ants **list)
{
	t_ants	*del;
	t_ants	*tmp;

	tmp = *list;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*list = NULL;
}
