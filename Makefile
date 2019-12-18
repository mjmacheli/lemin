# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 13:08:25 by mmacheli          #+#    #+#              #
#    Updated: 2018/09/20 10:33:03 by mmacheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBS = libft/libft.a

INCLUDES = lem_in.h

SRC = get_paths.c  main.c tools.c creation.c error_handling.c destruction.c\
	 bfs_search.c sort_paths.c move_ants.c creation2.c tools2.c destructon2.c

all: $(NAME)

$(NAME):
	@ make -C libft/ re
	@ $(CC) -o $(NAME) $(SRC) $(CFLAGS)  $(LIBS)
	@ echo "\033[31;1m$(NAME) successfully created!\033[0m"
	
clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31;1m$(NAME) removed!\033[0m"
	@echo "\033[31;1mlibft.a removed!\033[0m"

re: fclean all
	@make -C libft fclean re
