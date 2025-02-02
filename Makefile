# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 16:48:52 by ssoukoun          #+#    #+#              #
#    Updated: 2025/02/02 16:59:32 by ssoukoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini
CC = cc
HEAD = .
CFLAGS = -g3 -Wall -Werror -Wextra
LDFLAGS = -lreadline  # Ajout du linking readline
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)  # Génération des fichiers .o automatiquement


MAKE_FT_PRINTF = make -s -C ./printf
FT_PRINTF_A = ./printf/libftprintf.a
MAKE_LIBFT        =    make -s -C ./libft
LIBFT_A			=		./libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) ${LIBFT_A} ${FT_PRINTF_A} -o $(NAME) $(LDFLAGS)  # Link avec -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)  # Compilation des .c en .o

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
