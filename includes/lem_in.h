/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:30:33 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/23 14:30:36 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "structures.h"

int		g_ants;
int		g_check;
int		g_start;
int		g_end;
int		g_path_print;
int		g_leaks_print;
int		g_colors;

void	find_ways(t_room **map);
int		check_if_comments(char *arg);
int		check_if_start_or_end(char *line);
int		check_if_other_commands(char *line);
int		check_int(char *str, int min);
int		check_if_ants(char *arg);
int		check_if_rooms(char *line, t_list_of_args *list);
int		check_if_room_exist(t_list_of_args *list, char *key);
int		find_split_len(char **elements, int key);
void	free_arrays(char ***elements);
void	free_list_of_args(t_list_of_args **list);
void	free_connections(t_cnct **connections);
void	free_friends(t_friend **friend);
void	free_map(t_room **map);
void	free_element_in_list_of_paths(t_list_of_paths *current,
	t_list_of_paths **list);
void	free_all_paths(t_path *path);
void	free_list_of_paths(t_list_of_paths **list);
void	free_one_ant(t_ants **ant);
void	free_list_of_ants(t_ants **list);
void	ft_exit(char *str);
void	create_map(t_room **map, t_list_of_args *list);
int		add_link(t_cnct **cnctns, char *arg);
void	remove_invalid_elements_from_map(t_room **map);
int		check_if_links(char *line, t_list_of_args *list);
int		set_room_type(t_room **map, char room_type);
int		add_room_type(t_room **map, char *arg);
void	remove_last_element_from_map(t_room **map);
int		check_room_for_duplicates(t_room **map);
int		add_room(t_room **map, char *arg);
int		set_room_type(t_room **map, char room_type);
int		add_room_type(t_room **map, char *arg);
void	add_new_friends(t_room **current, t_room **map, char *name);
void	add_friends_list(t_room **map, t_cnct *cncntns);
void	create_first_path_in_list(t_room *start, t_room *add,
	int path_id, t_list_of_paths **list_of_paths);
void	add_new_list_to_list_of_paths(t_room *start, t_room *add,
	int path_id, t_list_of_paths **list_of_paths);
void	continue_paths_in_list_of_paths(t_room *add,
	t_list_of_paths **list_of_paths);
void	create_first_part_of_list_of_paths(t_queue **q, t_room **r,
	t_list_of_paths **list_of_paths);
void	create_paths(t_room **map, t_list_of_paths **list_of_paths);
int		check_paths_for_start_and_exit(t_list_of_paths **list);
void	add_line_to_list_of_args(char *line,
	t_list_of_args **list, char *type);
void	create_list_of_arguments(int fd, t_list_of_args **new);
void	move_ants(t_ants **list_of_ants);
void	create_and_print_result(t_list_of_args *list_of_args,
	t_list_of_paths *list_of_paths);
int		move_all_at_the_same_time(t_ants *ant_list,
	t_list_of_paths *path_list);
void	include_ant_into_queue(t_ants **ants, t_list_of_paths **paths);
void	create_ants_queue(t_ants **ants, t_list_of_paths **list_of_paths);
void	del_ant_from_list_of_ants(t_ants **list_of_ants, t_ants *current);
char	*move_one_ant(t_ants **ant, char *res);
char	*save_result(char *res, t_ants *ant, t_path *path);
void	print_paths_and_len(t_list_of_paths *list);
void	print_list_of_args(t_list_of_args *list);
char	*add_color(int num);
int		find_path_len(t_path *path);
char	*add_to_string(char *to, char *add);
void	add_friends_to_queue(t_queue **queue, char *name);

#endif
