# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsingh <fsingh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 16:48:52 by ssoukoun          #+#    #+#              #
#    Updated: 2025/02/04 16:23:10 by fsingh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini
CC = cc
HEAD = .
CFLAGS = -g3 -Wall -Werror -Wextra
LDFLAGS = -lreadline  # Ajout du linking readline
SOURCES = main.c parsing.c free_shell.c utils_parsing.c utils_parsing_2.c utils_parsing_3.c env_management.c
OBJECTS = $(SOURCES:.c=.o)  # Génération des fichiers .o automatiquement


MAKE_LIBFT        =    make -s -C ./libft
LIBFT_A			=		./libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) ${LIBFT_A} -o $(NAME) $(LDFLAGS)  # Link avec -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)  # Compilation des .c en .o

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
