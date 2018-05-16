/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:47:50 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 16:47:53 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*save_result(char *res, t_ants *ant, t_path *path)
{
	char	*ants;

	if (g_colors)
		res = add_to_string(res, add_color(path->id));
	ants = ft_itoa(ant->ant_num);
	res = add_to_string(res, "L");
	res = add_to_string(res, ants);
	res = add_to_string(res, "-");
	res = add_to_string(res, path->room->name);
	res = add_to_string(res, " ");
	if (g_colors)
		res = add_to_string(res, "\e[m");
	free(ants);
	return (res);
}

void	print_paths_and_len(t_list_of_paths *list)
{
	t_path	*path;
	int		i;

	i = 0;
	while (list)
	{
		path = list->path;
		i = 0;
		while (path)
		{
			ft_printf("%s", path->room->name);
			path = path->next;
			if (path)
				ft_printf("->");
			i++;
		}
		ft_printf(" (%i)\n", i - 1);
		list = list->next;
	}
	ft_printf("\n");
}

void	print_list_of_args(t_list_of_args *list)
{
	if (list)
		ft_printf("%i\n", g_ants);
	while (list)
	{
		ft_printf("%s\n", list->arg);
		list = list->next;
	}
	ft_printf("\n");
}

char	*add_color(int num)
{
	if (num % 13 == 0)
		return ("\e[32m");
	if (num % 13 == 1)
		return ("\e[35m");
	if (num % 13 == 2)
		return ("\e[36m");
	if (num % 13 == 3)
		return ("\e[33m");
	if (num % 13 == 4)
		return ("\e[31m");
	if (num % 13 == 5)
		return ("\e[34m");
	return ("\e[37m");
}
