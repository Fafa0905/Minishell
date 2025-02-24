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
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>

/*typedef struct s_lst
{
    char *line;
    s_lst *next;
    s_lst *pre;
}               t_lst;*/

typedef enum e_token_type
{
    TOKEN_ARG,
    TOKEN_PIPE,
    TOKEN_OUT,
    TOKEN_IN,
    TOKEN_APPEND,
    TOKEN_HEREDOC,
} t_token_type;

typedef struct s_token
{
    t_token_type    type;
    char            *value;
    struct s_token  *next;
} t_token;

typedef struct s_arg
{
    char        *content;
    struct s_arg *next;
} t_arg;

typedef struct s_command
{
    t_arg      *args;
    t_arg      *infile;
    t_arg       *outfile;
    t_arg      *append;
    t_arg      *heredoc;
    struct s_command *next;
} t_command;

typedef struct s_commandlist
{
    int                     *pipe;
    t_token                 *tokens;
    /*t_lst					**env;*/
    t_command               *cmd;
}                            t_commandlist;

//Parsing
void    handle_single_redirect(char *input, int *i, t_commandlist *mini, t_token_type token_type);
void    handle_pipe(char *input, int *i, t_commandlist *mini, t_token_type token_type);
int 	handle_arguments(char *input, int *i, t_commandlist *mini);
int 	lexing(char *input, t_commandlist *mini);
int	    parsing(char *input, t_commandlist *mini);

//Parsing2
t_command   *init_command(void);
int	        parse_token(t_commandlist *mini);

//Utils_Parsing_1
int     ispace(char c);
int     is_special(char c);
int	    only_space(char *input);
int	    open_quote(char *input);
char    *ft_strndup(const char *s, size_t n);

//utils_parsing_2
int	    checking_error_before(char *input);
int	    add_token(t_commandlist *mini, t_token_type type, char *token_value);
void    handle_double_redirect(char *input, int *i, t_commandlist *mini, t_token_type token_type);

//free
void    free_shell(t_commandlist    *mini);
void    clean_up_and_exit(char *input, t_commandlist *mini);
void    free_split(char **split);

//env
/*void	lux(t_commandlist *mini);
char    *look_env(t_commandlist *mini, char *tab);
void	set_env(t_commandlist *mini, char **env);
void	append_node(t_commandlist *mini, char *env);
t_lst	*find_last(t_lst *stack);*/

void	print_args(t_commandlist *mini);
void print_commands(t_command *cmd);

# endif