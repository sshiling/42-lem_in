/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:41:30 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 19:41:32 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_int(char *str, int min)
{
	char	*temp;
	int		num;

	num = ft_atoi(str);
	temp = ft_itoa(num);
	if (ft_strcmp(str, temp))
	{
		free(temp);
		return (0);
	}
	free(temp);
	if (min > num)
		return (0);
	return (1);
}

int		check_if_ants(char *arg)
{
	if (g_check != 0)
		return (0);
	if (!check_int(arg, 1))
		return (0);
	g_check = 1;
	return (1);
}
