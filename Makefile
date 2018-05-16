# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshiling <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:01:36 by sshiling          #+#    #+#              #
#    Updated: 2017/10/11 23:20:04 by sshiling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror

SRC_NAME = main.c check_if_comment_or_command.c check_if_ants.c \
	check_if_room.c create_structures.c free_functions.c \
	ft_exit.c create_map.c add_room_to_map.c add_friends_connections.c \
	create_ways.c create_paths.c create_list_of_args.c \
	find_place_for_room_on_map.c create_paths_2.c \
	move_ants_1.c move_ants_2.c printers.c helpers.c \
	create_structures_2.c free_functions_2.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = -Iincludes/ -I$(LIB_DIR)includes/

LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@echo "##### Lib created #####"
	@gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft
	@echo "##### Compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Linking" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re

