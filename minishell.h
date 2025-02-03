/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:44:19 by ssoukoun          #+#    #+#             */
/*   Updated: 2025/02/03 17:16:55 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <sys/wait.h>


typedef enum token
{
    NO_DEF,
    CMD,
    PIPE,
    QUOTE,
    D_QUOTE,
    DOLLAR,
    IN,
    D_IN,
    OUT,
    D_OUT,
    FD
}s_token;

typedef struct part
{
    char     *part;
    char    **args;
    char    *cmd;
    int 
    s_token      type;
}				t_p;

typedef struct mini
{
	t_p		*pieces;

}				t_mini;

#endif