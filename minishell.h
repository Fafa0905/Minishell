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
int		count_special_char(char *arg);
char    **split_special(char *arg, t_commandlist *mini);
void	special_characters(t_commandlist *mini);
char	*extract_arg(char *input, int start, int end);
void	split_space(char *input, t_commandlist *mini);
int	    open_quote(char *input);
void	parsing(char *input, t_commandlist *mini);

//Utils
int     count_special_arg(char **args);
int     count_arg(char *input);
int     is_special(char c);
int     ispace(char c);
int     find_lenght_arg_space(char *input, int i);
void    free_shell(t_commandlist    *mini);

void	print_args(t_commandlist *mini);

#endif