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
	if (c && (c == ' ' || c == '\n' || c == '\r' || c == '\f' || c == '\t' \
	|| c == '\v'))
        return (1);
    return (0);
}

int is_special(char c)
{
    if (c == '|' || c == '<' || c == '>')
        return (1);
    return (0);
}

int count_special_arg(char **args)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (args[i])
    {
        count += count_special_char(args[i]);
        i++;
    }
    return (count);
}

int		count_special_char(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(arg[i])
	{
		if (is_special(arg[i]))
		{
			count++;
			if (arg[i + 1] && arg[i] == arg[i + 1])
				i++;
		}
		else
		{
			count++;
			while (arg[i] && !is_special(arg[i]))
				i++;
			continue;
		}
		i++;
	}
	return (count);
}

int count_arg(char *input)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (input[i])
    {
        while (ispace(input[i]))
            i++;
        if (input[i])
        {
            count++;
            i = find_lenght_arg_space(input, i);
        }
    }
    return (count);
}
