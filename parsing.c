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

char    **split_special(char *arg, t_commandlist *mini)
{
    char    **result;
	char	*special;
	int		end;
	char	*normal_arg;
    int     i;
    int     start;
    int     count;

    i = 0;
    start = 0;
    count = 0;
    result = malloc(sizeof(char *) * (count_special_char(arg) + 1));
	if (!result)
		free_shell(mini);
	while (arg[i])
	{
		while (ispace(arg[i]))
			i++;
		start = i;
		if (is_special(arg[i]))
		{
			special = extract_special_seq(&arg[i], mini);
			if (!special)
				free_shell(mini);
			add_arguments(result, &count, special);
			i += (is_double_special(&arg[i]) ? 2 : 1);
		}
		else
		{
			end = find_lenght_arg_space(arg, i);
			normal_arg = extract_arg(arg, start, end);
			add_arguments(result, &count, normal_arg);
			i = end;
		}
	}
	result[count] = NULL;
	return (result);
}

void	special_characters(t_commandlist *mini)
{
	char	**arg;
	char	**final_args;
	char	**split;
	int		i;
	int		j;
	int		count;

	i = 0;
	arg = mini->arguments;
	count = count_special_arg(arg) + 1;
	final_args = malloc(sizeof(char *) * count);
	printf("count = %d\n", count);
	count = 0;
	if (!final_args)
	{
		free_shell(mini);
		return;
	}
	while(arg[i])
	{
		split = split_special(arg[i], mini);
		j = 0;
		while (split[j])
		{
			final_args[count] = split[j];
			if (!final_args)
				free_shell(mini);
			j++;
			count++;
		}
		free(split);
		i++;
	}
	final_args[count] = NULL;
	mini->arguments = final_args;
}

char	*extract_arg(char *input, int start, int end)
{
	char	*arg;
	int		i;
	int		j;

	arg = malloc(sizeof(char) * (end - start + 1));
	if (!arg)
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
		arg[j++] = input[i++];
	arg[j] = '\0';
	return (arg);
}

int	split_space(char *input, t_commandlist *mini)
{
	char	**arg;
	int		i;
	int		start;
	int		count;

	i = 0;
	count = 0;
	arg = malloc(sizeof(char *) * (count_arg(input) + 1));
	if (!arg)
		return (1);
	while (input[i])
	{
		while (ispace(input[i]))
			i++;
		if (input[i])
		{
			start = i;
			i = find_lenght_arg_space(input, i);
			arg[count] = extract_arg(input, start, i);
			if (!arg[count])
			{
				free_split(arg, count);
                return (1);
			}
			count++;
		}
	}
	arg[count] = NULL;
	mini->arguments = arg;
	return (0);
}

int	parsing(char *input, t_commandlist *mini)
{
	if (strcmp(input, "exit") == 0)
		clean_up_and_exit(input, mini);
	if (only_space(input))
	{
		free_shell(mini);
		return (1);
	}
	if(open_quote(input))
	{
		free_shell(mini);
		return (1);
	}
	if (split_space(input, mini) == 1)
		return (1);
	if (has_special(mini->arguments))
		special_characters(mini);
	print_args(mini);
	return (0);
}

void	print_args(t_commandlist *mini)
{
	int i;

	i = 0;
	if (mini && mini->arguments)
	{
		while (mini->arguments[i])
		{
			printf("Argument %d: %s\n", i, mini->arguments[i]);
			i++;
		}
	}
	else
		printf("pas d'arguments.\n");
}