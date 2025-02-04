/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:43:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/04 14:22:50 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cmp(char str, char c)
{
	if (str == c)
		return (-1);
	return (0);
}

int	pars_a(char *str)
{
	int	fl;
	int	fld;
	int	i;

	fl = 0;
	fld = 0;
	i = 0;
	while (str[i])
	{
		if (ft_cmp (str[i], '"') == -1)
			fld++;
		if (ft_cmp (str[i], 39) == -1)
			fl++;
		i++;
	}
	if (fl % 2 != 0 || fld % 2 != 0)
		return (ft_printf("quotes unclosed\n"), -1);
	return (0);
}



int	main(int ac, char **argv, char **env)
{
	t_mini	*mini;
    char	*str;
	(void)argv;
	(void)ac;
	(void)env;


	mini = NULL;
	while (1)
	{
		str = readline("user:");
		add_history(str);
		if (pars_a(str) == -1)
			break;
		
	}
	return (0);
}