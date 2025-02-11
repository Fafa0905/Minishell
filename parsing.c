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
			i--;
		}
		i++;
	}
	return (count);
}

int	is_double_special(char *arg)
{
	return ((arg[0] == '>' && arg[1] == '>') || (arg[0] == '<' && arg[1] == '<'));
}

char	*extract_special_seq(char	*arg, t_commandlist *mini)
{
	char	*special;

	if (is_double_special(arg))
	{
		special = malloc(3);
		if (!special)
			free_shell(mini);
		special[0] = arg[0];
		special[1] = arg[1];
		special[2] = '\0';
	}
	else
	{
		special = malloc(2);
		if (!special)
			return (NULL);
		special[0] = arg[0];
		special[1] = '\0';
	}
	return (special);
}

void	add_arguments(char **result, int *count, char *arg)
{
	result[*count] = arg;
	(*count)++;
}

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
	count = 0;
	arg = mini->arguments;
	final_args = malloc(sizeof(char *) * count_special_arg(arg) + 1);
	if (!final_args)
		free_shell(mini);
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
	//free_split(mini->arguments);//
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

void	split_space(char *input, t_commandlist *mini)
{
	char	**arg;
	int		i;
	int		start;
	int		count;

	i = 0;
	count = 0;
	arg = malloc(sizeof(char *) * (count_arg(input) + 1));
	if (!arg)
		free_shell(mini);
	while (input[i])
	{
		while (ispace(input[i]))
			i++;
		if (input[i])
		{
			start = i;
			i = find_lenght_arg_space(input, i);
			arg[count] = extract_arg(input, start, i);
			count++;
		}
	}
	arg[count] = NULL;
	mini->arguments = arg;
	//free_split(arg);//
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

void	parsing(char *input, t_commandlist *mini)
{
	if(open_quote(input))
		free_shell(mini);
	if (!mini)
	{
		printf("Error: mini is NULL\n");
		return;
	}
	split_space(input, mini);
	special_characters(mini);
	print_args(mini);
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