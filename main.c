/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:43:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/02 17:41:00 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	type(char c)
{
	if (c == "'")
		return(1);
	if (c == "|")
		return(1);
	if (c == ";")
		return(1);
	if (c == "'")
		return(1);
}

int cases()

char **parse_uno(char *str, t_mini *mini)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		type()
	}
	
}

int	main(int ac, char **argv)
{
	t_mini	*mini;
    char	*str;
	(void)argv;
	(void)ac;
	int i;
	
	i = 0;
	str = readline("user:");
	free(str);
	return (0);
}