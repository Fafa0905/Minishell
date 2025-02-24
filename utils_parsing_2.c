/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsingh <fsingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:51:41 by fsingh            #+#    #+#             */
/*   Updated: 2025/02/24 13:35:39 by fsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checking_error_before(char *input)
{
	if (only_space(input))
		return (1);
	if (open_quote(input))
		return (1);
	/*if (start_or_end_meta(input))
		return (1);
	if (metacharacter_checking(input))
		return (1);
	if (redirect_checking(input))
		return (1);*/
	return (0);
}

int	add_token(t_commandlist *mini, t_token_type type, char *token_value)
{
	t_token	*new_token;
	t_token	*temp;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (1);
	new_token->type = type;
	new_token->value = ft_strdup(token_value);
	if (!new_token->value)
	{
		free (new_token);
		return (1);
	}
	new_token->next = NULL;
	if (!mini->tokens)
		mini->tokens = new_token;
	else
	{
		temp = mini->tokens;
		while (temp->next)
			temp = temp->next;
		temp->next = new_token;
	}
	printf("Création du token -> Adresse : %p, Valeur : %p (%s), Type : %d\n", (void *)new_token, (void *)new_token->value, new_token->value, new_token->type);
	return (0);
}

void handle_double_redirect(char *input, int *i, t_commandlist *mini, t_token_type token_type)
{
	int		start;
	char	*file;

	(*i) += 2;
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
