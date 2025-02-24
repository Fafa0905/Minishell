/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:56:48 by fsingh            #+#    #+#             */
/*   Updated: 2025/02/04 19:03:10 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handle_single_redirect(char *input, int *i, t_commandlist *mini, t_token_type token_type)
{
	int		start;
	char	*file;

	(*i) += 1;
	while (input[*i] && isspace(input[*i]))
		(*i)++;
	start = *i;
	while (input[*i] && !isspace(input[*i]) && !is_special(input[*i]))
		(*i)++;
	file = ft_strndup(&input[start], *i - start);
	add_token(mini, token_type, file);
	free (file);
	while (input[*i] && isspace(input[*i]))
		(*i)++;
}

void handle_pipe(char *input, int *i, t_commandlist *mini, t_token_type token_type)
{
	add_token(mini, token_type, "|");
	(*i)++;
	while (input[*i] && isspace(input[*i]))
		(*i)++;
}

int	handle_arguments(char *input, int *i, t_commandlist *mini)
{
	int		start;
	char	quote;
	char	*current_token;

	current_token = NULL;
	start = *i;
	while (input[*i] && !is_special(input[*i]) && !isspace(input[*i]))
	{
		if (input[*i] == '\'' || input[*i] == '"')
		{
			quote = input[*i];
			(*i)++;
			while (input[*i] && input[*i] != quote)
			{
				(*i)++;
				if (input[*i] == '\0')
					return (1);
			}
			(*i)++;
		}
		else
			(*i)++;
	}
	current_token = ft_strndup(&input[start], *i - start);
	if (!current_token)
		return (1);
	add_token(mini, TOKEN_ARG, current_token);
	free(current_token);
	while (input[*i] && isspace(input[*i]))
		(*i)++;
	return (0);
}

int	lexing(char *input, t_commandlist *mini)
{
	int		i;

	mini->tokens = NULL;
	i = 0;
	while (input[i])
	{
		while (isspace(input[i]))
			i++;
		if (is_special(input[i]))
		{
			if (input[i] == '|')
				handle_pipe(input, &i, mini, TOKEN_PIPE);
			else if (input[i] == '>' && input[i + 1] == '>')
				handle_double_redirect(input, &i, mini, TOKEN_APPEND);
			else if (input[i] == '<' && input[i + 1] == '<')
				handle_double_redirect(input, &i, mini, TOKEN_HEREDOC);
			else if (input[i] == '>')
				handle_single_redirect(input, &i, mini, TOKEN_OUT);
			else if (input[i] == '<')
				handle_single_redirect(input, &i, mini, TOKEN_IN);
		}
		else
		{	if (handle_arguments(input, &i, mini))
				return (1);
		}
		while (isspace(input[i]))
			i++;
	}
	return (0);
}

int	parsing(char *input, t_commandlist *mini)
{
	if (strcmp(input, "exit") == 0)
		clean_up_and_exit(input, mini);
	if (checking_error_before(input))
		return (1);
	if (lexing(input, mini) == 1)
		return (1);
	if (parse_token(mini) == 1)
		return (1);
	/*lux(mini);
	build_in(mini);*/
	print_args(mini);
	print_commands(mini->cmd);
	return (0);
}
void print_args(t_commandlist *mini)
{
	t_token *temp_tokens;
	
	temp_tokens = mini->tokens;
    while (temp_tokens)
    {
        printf("Token: %s, Type: %d\n", temp_tokens->value, temp_tokens->type);
        temp_tokens = temp_tokens->next;
    }
}

void print_redirections(t_arg *redir, const char *type)
{
    while (redir)
    {
        printf("  %s: %s\n", type, redir->content);
        redir = redir->next;
    }
}

void print_commands(t_command *cmd)
{
	t_command	*temp;

	temp = cmd;
    while (temp)
    {
        printf("Commande:\n");
        
        // Affiche les arguments
        t_arg *arg = temp->args;
        while (arg)
        {
            printf("  Argument: %s\n", arg->content);
            arg = arg->next;
        }

        // Affiche les redirections si elles existent
        if (temp->infile)
            print_redirections(temp->infile, "Infile");
        if (temp->outfile)
            print_redirections(temp->outfile, "Outfile");
        if (temp->append)
            print_redirections(temp->append, "Append");
        if (temp->heredoc)
            print_redirections(temp->heredoc, "Heredoc");
        temp = temp->next;
    }
}