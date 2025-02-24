/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:57:40 by fsingh            #+#    #+#             */
/*   Updated: 2025/02/04 19:13:46 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ispace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\f' || c == '\t' \
	|| c == '\v')
        return (1);
    return (0);
}

int is_special(char c)
{
    if (c == '|' || c == '<' || c == '>')
        return (1);
    return (0);
}

int	only_space(char *input)
{
	int	i;

	i = 0;
	if (!input || input[0] == '\0')
		return (1);
	while (input[i])
	{
		if (!ispace(input[i]))
			return (0);
		i++;
	}
	return (1);
}

char *ft_strndup(const char *str, size_t n)
{
    char *res;
    size_t i;

    i = 0;
    res = (char *)malloc(n + 1);
    if (res == NULL)
        return (NULL);
    while (i < n && str[i] != '\0')
    {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

int	open_quote(char *input)
{
	int		i;
	char	quote;

	i = 0;
	if (!input)
		return(0);
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i];
			i++;
			while (input[i] && input[i] != quote)
				i++;
			if (!input[i])
				return (1);
		}
		i++;
	}
	return (0);
}
