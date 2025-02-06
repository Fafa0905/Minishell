/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsingh <fsingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:43:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/04 17:58:05 by fsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	main(int ac, char **argv, char **env)
{
	t_commandlist	*mini;
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
	parsing(input, mini);
	add_history(input);
	free(input);
	}
	return (0);
}