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

t_commandlist	*init_shell()
{
	t_commandlist	*mini;

	mini = malloc(sizeof(t_commandlist));
	if (!mini)
		return (NULL);
	mini->tokens = NULL;
	mini->cmd = NULL;
	return (mini);
}

int	main(int ac, char **argv, char **env)
{
	t_commandlist	*mini;
    char	*input;
	(void)argv;
	(void)ac;
	(void)env;

	mini = init_shell();
	if (!mini)
		return (printf("Error allocating memory\n"), 1);
	/*set_env(mini, env);*/
	while (1)
	{
		input = readline("user:");
		if (!input)
		{
			free(input);
			return (1);
		}
		if (*input)
			add_history(input);
		if (parsing(input, mini) != 0)
		{
			free(input);
			continue;
		}
		free(input);
		free_shell(mini);
	}
	free(mini);
	rl_clear_history();
	return (0);
}
