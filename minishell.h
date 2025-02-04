/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsingh <fsingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:44:19 by ssoukoun          #+#    #+#             */
/*   Updated: 2025/02/04 17:58:05 by fsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <sys/wait.h>

# define IN 		1
# define HEREDOC	2
# define OUT		3
# define D_OUT		4
# define PIPE		5
# define CMD		6
# define ARG		7
# define DOLLAR     8

typedef struct s_cmd
{
    int             infile;
    int             outfile;
    char            **cmd_param;
	struct s_token	*prev;
	struct s_token	*next;
}              t_cmd;

typedef struct token
{
    char            *value;
    int             type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct mini
{
	t_token *token;
    t_cmd   *cmd;  
}				t_mini;

#endif