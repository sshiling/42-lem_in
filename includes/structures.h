/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:59:48 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/08 17:59:49 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct				s_room
{
	char					*name;
	char					type;
	int						x;
	int						y;
	int						status;
	int						depth;
	int						path;
	int						ant;
	struct s_friend			*friends;
	struct s_room			*next;
}							t_room;

typedef struct				s_cnct
{
	char					*room_1;
	char					*room_2;
	struct s_cnct			*next;
}							t_cnct;

typedef struct				s_list_of_args
{
	char					*arg;
	char					*type;
	struct s_list_of_args	*next;
}							t_list_of_args;

typedef struct				s_friend
{
	struct s_room			*room;
	struct s_friend			*next;
}							t_friend;

typedef struct				s_queue
{
	char					*content;
	struct s_queue			*next;
}							t_queue;

typedef struct				s_path
{
	int						id;
	int						ant_num;
	struct s_room			*room;
	struct s_path			*next;
}							t_path;

typedef struct				s_list_of_paths
{
	struct s_path			*path;
	struct s_list_of_paths	*next;
}							t_list_of_paths;

typedef struct				s_ants
{
	int						ant_num;
	int						queue;
	t_path					*path;
	struct s_ants			*next;
}							t_ants;
t_list_of_args				*create_new_list_of_args(void);
t_room						*create_new_room(void);
t_cnct						*create_new_cnctn(void);
t_friend					*create_new_friend(void);
t_list_of_paths				*create_new_list_of_paths(void);
t_path						*create_new_path(void);
t_queue						*create_new_queue(char *content);
t_ants						*create_new_ant(void);
t_ants						*create_list_of_ants(void);
t_room						*find_place_for_room(t_room **map);
t_friend					*find_shortest_path(t_room *room);
t_path						*choose_shortest_path(t_list_of_paths **paths);
t_room						*find_exit(t_room *map);
t_room						*find_room_by_name(t_room *room, char *name);

#endif
