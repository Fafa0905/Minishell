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

void	*create_token(t_token **tokens, char *cmd_line, t_mini *mini)
{
	(*tokens) = NULL;

	while (*cmd_line)
	{
		while (isspace(*cmd_line))
			cmd_line++;
        if (!*cmd_line)
            break;
        if (is_special(cmd_line))
		{
			if (!add_special(tokens, &cmd_line))
				free_shell(mini);
		}
		else
		{
			if (!add_cmd(tokens, &cmd_line))
				free_shell(mini);
		}
	}
}

void	parsing(char *input, t_mini *mini)
{
	if(open_quote(mini, input))
		free_shell(mini);
	replace_dollar(&input, mini);
	create_token(&mini->token, input, mini);
}

void	add_special(t_token **tokens, char *cmd_line)
{
	
}