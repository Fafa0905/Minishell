/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:44:19 by ssoukoun          #+#    #+#             */
/*   Updated: 2025/02/04 19:02:05 by ssoukoun         ###   ########.fr       */
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


typedef struct s_outfilelist
{
    int                     overwrite;
    int                     append;
    char                    *name;
    struct s_outfilelist    *next;
}                            t_outfile;

typedef struct s_commandlist
{
    int                     built_in;
    int                     pipe;
    char                    **arguments;
    int                     count_arg;
    char                    **infile;
    char                    **heredoc;
    t_outfile               *outfile;
    struct s_commandlist    *next;
}                            t_commandlist;

//Parsing
void	*create_token(t_token **tokens, char *cmd_line, t_mini *mini);
void	parsing(char *input, t_mini *mini);

//Utils
int is_special(char *str);
int ispace(char c);

#endif