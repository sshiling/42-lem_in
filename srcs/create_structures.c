/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:16:13 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 21:16:15 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path				*create_new_path(void)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	new->room = NULL;
	new->id = 0;
	new->ant_num = 0;
	new->next = NULL;
	return (new);
}

t_queue				*create_new_queue(char *content)
{
	t_queue	*new;

	new = (t_queue*)malloc(sizeof(t_queue));
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}

t_ants				*create_new_ant(void)
{
	t_ants	*new;

	new = (t_ants*)malloc(sizeof(t_ants));
	new->queue = OFF;
	new->path = NULL;
	new->next = NULL;
	new->ant_num = 0;
	return (new);
}

t_ants				*create_list_of_ants(void)
{
	int		i;
	t_ants	*new;
	t_ants	*tmp;

	i = 1;
	new = create_new_ant();
	tmp = new;
	while (i <= g_ants)
	{
		tmp->ant_num = i;
		i++;
		if (i <= g_ants)
		{
			tmp->next = create_new_ant();
			tmp = tmp->next;
		}
	}
	return (new);
}
