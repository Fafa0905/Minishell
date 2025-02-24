/*#include "minishell.h"

void	lux(t_commandlist *mini)
{
	char **tab;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	tab = mini->arguments;
	while (tab[i])
	{
		if (tab[i][j] == '"' && tab[i][j + 1] == '$')
			tab[i] = look_env(mini, tab[i]);
		i++;
	}
	
}

char *look_env(t_commandlist *mini, char *tab)
{
	int	i;
	char	*line;

	i = 0;
	tab = ft_strtrim(tab, "\"");
	while (mini->env[i]->line)
	{
		line = ft_strnstr(mini->env[i]->line, (tab+ 1), ft_strlen(tab));
		if (line)
			return (ft_strdup(mini->env[i]->line + ft_strlen(tab) + 1));
		i++;
	}
	return (tab);
}

void	set_env(t_commandlist *mini, char **env)
{
	int	i;

	i = 0;
	if (!env)
		(printf("YArien a gratter \n"), exit(0));
	while (env[i])
		append_node(mini, env[i++]);
	

}

void	append_node(t_commandlist *mini, char *env)
{
	t_lst	*newnode;
	t_lst	*last;

	newnode = malloc(sizeof(t_lst));
	if (newnode == NULL)
		return ;
	newnode->next = NULL;
	newnode->line = ft_strdup(env);
	if (mini->env == NULL)
	{
		mini->env = newnode;
		newnode->pre = NULL;
	}
	else
	{
		last = find_last(mini->env);
		last->next = newnode;
		newnode->pre = last;
	}
}

t_lst	*find_last(t_lst *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}*/