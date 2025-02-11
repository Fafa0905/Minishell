#include "minishell.h"

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

int	ft_strnstri(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (!*needle)
		return (-1);
	while (haystack[i] && i < len)
	{
		a = 0;
		while (haystack[i + a] && needle[a] && haystack[i + a] && len > i + a
			&& haystack[i + a] == needle[a])
			a++;
		if (!needle[a])
			return (1);
		i++;
	}
	return (-1);
}