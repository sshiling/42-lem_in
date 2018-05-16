/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:31:41 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 18:31:43 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	if_check_leaks(void)
{
	if (g_leaks_print)
		system("leaks --quiet lem-in");
}

int		check_list_of_args(t_list_of_args *list)
{
	int start;
	int end;
	int room;
	int link;

	start = 0;
	end = 0;
	room = 0;
	link = 0;
	while (list)
	{
		if (!ft_strcmp(list->arg, "##start"))
			start++;
		if (!ft_strcmp(list->arg, "##end"))
			end++;
		if (!ft_strcmp(list->type, "room"))
			room++;
		if (!ft_strcmp(list->type, "link"))
			link++;
		list = list->next;
	}
	if (start != 1 || end != 1 || room < 2 || link < 1)
		return (0);
	return (1);
}

void	check_argv(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2)
		return ;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-u") || (ft_strcmp(argv[i], "-l")
			&& ft_strcmp(argv[i], "-p") && ft_strcmp(argv[i], "-c")))
		{
			ft_printf("%s\n", "Usage:\n[-u] for usage info\n[-l] \
for leaks check\n[-p] for paths print\n[-c] for \
paths visualization\n\nGive arguments through command \
line.\nArguments should contain number of ants,\nrooms, \
commands, comments\nand links between rooms.\n");
			ft_exit(NULL);
		}
		if (!ft_strcmp(argv[i], "-l"))
			g_leaks_print = ON;
		if (!ft_strcmp(argv[i], "-p"))
			g_path_print = ON;
		if (!ft_strcmp(argv[i], "-c"))
			g_colors = ON;
		i++;
	}
}

void	read_args_and_create_map(t_list_of_args **list_of_args,
	t_room **map, int argc, char **argv)
{
	check_argv(argc, argv);
	create_list_of_arguments(0, list_of_args);
	if (!list_of_args)
		ft_exit("There are no arguments");
	if (!check_list_of_args(*list_of_args))
		ft_exit("Error with arguments");
	create_map(map, *list_of_args);
	if (!(*map))
		ft_exit("Map Error");
	find_ways(map);
}

int		main(int argc, char **argv)
{
	t_list_of_args		*list_of_args;
	t_list_of_paths		*list_of_paths;
	t_room				*map;

	map = NULL;
	list_of_args = NULL;
	list_of_paths = create_new_list_of_paths();
	read_args_and_create_map(&list_of_args, &map, argc, argv);
	create_paths(&map, &list_of_paths);
	if (!list_of_paths->path || !check_paths_for_start_and_exit(&list_of_paths))
		ft_exit("Absent connections between start and end");
	create_and_print_result(list_of_args, list_of_paths);
	free_list_of_args(&list_of_args);
	free_list_of_paths(&list_of_paths);
	free_map(&map);
	if_check_leaks();
	return (0);
}
