/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsingh <fsingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:43:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/04 16:23:07 by fsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*add_token(char *str, t_mini *mini, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		free_all(mini);
	token->type = type;
	token->value = ft_strdup(str);
	token->next = NULL;
	if (!mini->token)
		mini->token = token;
	else
	{
		t_token *tmp = mini->token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
	}
}

void	tokenize(char *str, t_mini *mini)
{
	int		i;

	i = 0;
	while(str[i])
	{
		while (isspace(str[i]))
			i++;
		if (str[i] == '\'' || str[i] == '"')
			extract_token_quoted(str, &i, mini);
		else
		{
			int start = i;
			while (str[i] && !isspace(str[i]) &&)
		}
	}
}

int	main(int ac, char **argv, char **env)
{
	t_mini	*mini;
    char	*input;
	(void)argv;
	(void)ac;
	int i;
	
	i = 0;
	while (1)
	{
	input = readline("user:");
	if (!input)
	{
		free_shell(mini);
		break;
	}
	tokenize(input, mini);
	add_history(input);
	free(input);
	}
	return (0);
}