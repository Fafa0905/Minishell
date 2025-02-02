# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 05:29:00 by ssoukoun          #+#    #+#              #
#    Updated: 2025/01/06 11:10:13 by ssoukoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COMP = gcc -Wall -Wextra -Werror 

MANDATORY_SRC = \
                ft_printex.c    \
				ft_printf.c     \
				ft_wrtchar_fd.c \
				ft_wrtnbr_fd.c  \
                ft_wrtstr_fd.c  \
				ft_ptr.c		\
				ft_wrtunsnbr_fd.c

OBJ_MANDATORY = ${MANDATORY_SRC:.c=.o}

%.o: %.c
		${COMP} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ_MANDATORY}
		ar rcs ${NAME} ${OBJ_MANDATORY}

clean:
		rm -f ${OBJ_MANDATORY}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re