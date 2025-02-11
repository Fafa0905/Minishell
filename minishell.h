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

typedef struct s_lst
{
    char *line;
    s_lst *next;
    s_lst *pre;
}               t_lst;

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
char    **split_special(char *arg, t_commandlist *mini);
void	special_characters(t_commandlist *mini);
char	*extract_arg(char *input, int start, int end);
int 	split_space(char *input, t_commandlist *mini);
int	    parsing(char *input, t_commandlist *mini);

//Utils_Parsing_1
int     ispace(char c);
int     is_special(char c);
int     count_special_arg(char **args);
int		count_special_char(char *arg);
int     count_arg(char *input);

//Utils_Parsing_2
int	    has_special(char **arg);
int	    only_space(char *input);
int     find_lenght_arg_space(char *input, int i);
int	    is_double_special(char *arg);
void	add_arguments(char **result, int *count, char *arg);

//Utils_3
char	*extract_special_seq(char	*arg, t_commandlist *mini);
int	    open_quote(char *input);

//free
void    free_shell(t_commandlist    *mini);
void    free_split(char **split, int count);
void    clean_up_and_exit(char *input, t_commandlist *mini);

//env
void	lux(t_commandlist *mini);
char    *look_env(t_commandlist *mini, char *tab);
void	set_env(t_commandlist *mini, char **env);
void	append_node(t_commandlist *mini, char *env);
t_lst	*find_last(t_lst *stack);

void	print_args(t_commandlist *mini);

#endif