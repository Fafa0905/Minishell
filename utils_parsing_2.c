#include "minishell.h"

int	has_special(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		if (ft_strchr(arg[i], '>') || ft_strchr(arg[i], '<') || ft_strchr(arg[i], '|'))
			return (1);
		i++;
	}
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

int find_lenght_arg_space(char *input, int i)
{
    char quote;

    while (input[i] && !isspace(input[i]))
    {
        if (input[i] == '\'' || input[i] == '"')
        {
            quote = input[i];
            i++;
            while (input[i] && input[i] != quote)
                i++;
            if (input[i])
                i++;
            return (i);
        }
        else
            i++;
    }
    return (i);
}

int	is_double_special(char *arg)
{
	return ((arg[0] == '>' && arg[1] == '>') || (arg[0] == '<' && arg[1] == '<'));
}

void	add_arguments(char **result, int *count, char *arg)
{
	result[*count] = arg;
	(*count)++;
}