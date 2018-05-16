/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:39:30 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 16:39:35 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_split_len(char **elements, int key)
{
	int		i;

	i = -1;
	while (elements[++i])
		;
	if (i != key)
		return (1);
	return (0);
}

int			check_for_spaces(char *line)
{
	int		i;
	int		key;

	i = 0;
	key = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			key++;
		i++;
	}
	if (key != 2)
		return (0);
	return (1);
}

int			check_coordinates(char **elements)
{
	int		i;

	i = -1;
	while (elements[1][++i])
		if (!(ft_isdigit(elements[1][i])))
			return (0);
	i = -1;
	while (elements[2][++i])
		if (!(ft_isdigit(elements[2][i])))
			return (0);
	return (1);
}

int			check_if_rooms(char *line, t_list_of_args *list)
{
	char	**elements;
	int		i;

	i = -1;
	if (g_check != 1 || ft_strchr(line, '-') ||
		line[0] == 'L' || line[0] == '#')
		return (0);
	elements = ft_strsplit(line, ' ');
	if (!check_for_spaces(line) || find_split_len(elements, 3)
		|| !elements[0] || check_if_room_exist(list, elements[0])
		|| !check_coordinates(elements))
	{
		free_arrays(&elements);
		return (0);
	}
	free_arrays(&elements);
	return (1);
}

int			check_if_room_exist(t_list_of_args *list, char *key)
{
	char	**elements;

	while (list)
	{
		if (!ft_strcmp(list->type, "room"))
		{
			elements = ft_strsplit(list->arg, ' ');
			if (!ft_strcmp(elements[0], key))
			{
				free_arrays(&elements);
				return (1);
			}
			free_arrays(&elements);
		}
		list = list->next;
	}
	return (0);
}
