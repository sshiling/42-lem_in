/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:03:28 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 21:03:29 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit(char *str)
{
	if (!str)
	{
		if (g_leaks_print)
			system("leaks --quiet lem-in");
		exit(1);
	}
	else
		ft_printf("%s\n", str);
	if (g_leaks_print)
		system("leaks --quiet lem-in");
	exit(1);
}
