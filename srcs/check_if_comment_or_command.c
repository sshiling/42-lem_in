/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_comment_or_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:03:21 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 20:03:23 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_if_comments(char *arg)
{
	if (ft_strlen(arg) < 1 || arg[0] != '#')
		return (0);
	if (ft_strlen(arg) > 1 && arg[1] == '#')
		return (0);
	return (1);
}

int		check_if_start_or_end(char *line)
{
	if (g_ants < 0)
		return (0);
	if (!ft_strcmp(line, "##start") && g_start == 0 && g_check != 0)
	{
		g_start = 1;
		return (1);
	}
	if (!ft_strcmp(line, "##end") && g_end == 0 && g_check != 0)
	{
		g_end = 1;
		return (1);
	}
	return (0);
}

int		check_if_other_commands(char *line)
{
	if (line[0] == '#' && line[1] == '#' &&
		ft_strcmp(line, "##start") && ft_strcmp(line, "##end"))
		return (1);
	return (0);
}
