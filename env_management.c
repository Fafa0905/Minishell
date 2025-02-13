#include "minishell.h"

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
		mini->env= newnode;
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
}
void	build_in(t_commandlist *mini)
{
	
	if (ft_strncmp(mini->arguments[0], "exit", ft_strlen("exit")))
		ft_exit(mini);
	if (ft_strncmp(mini->arguments[0], "echo", ft_strlen("echo")))
		ft_echo(mini);
	if (ft_strncmp(mini->arguments[0], "env", ft_strlen("env")))
		ft_env(mini);
	if (ft_strncmp(mini->arguments[0], "unset", ft_strlen("unset")))
		ft_unset(mini);
	if (ft_strncmp(mini->arguments[0], "export", ft_strlen("export")))
		ft_export(mini);
	if (ft_strncmp(mini->arguments[0], "pwd", ft_strlen("pwd")))
		ft_pwd(mini);
	if (ft_strncmp(mini->arguments[0], "cd", ft_strlen("cd")))
		ft_cd(mini);

}

void	ft_exit(t_commandlist *mini)
{
	if (mini->arguments[1])
		return ;
	else
		clean_up_and_exit(NULL, mini);
}

void	ft_echo(t_commandlist *mini)
{
	int	i;
	
	i = 0;
	while (mini->arguments[i])
		write(mini->pipe[0], mini->arguments[i], ft_strlen(mini->arguments[i++]));

}
void	ft_env(t_commandlist *mini)
{
	int	i;

	i = 0;
	while(mini->env[i])
	{
		write(mini->pipe, mini->env[i], ft_strlen(mini->env[i++]));
		write (mini->pipe, '\n', 1);
	}
	
}
void	ft_unset(t_commandlist *mini)
{
	int	i;
	int	j;

	i = 0;

	while (mini->env[i])
	{
		j = 0;
		while(mini->arguments[j])
		{
			if(ft_strncmp(mini->env[i]->line, mini->arguments[j], ft_strlen(mini->arguments[j])))
				deletenode(mini->env[i]);
			j++;
		}
		i++;
	}
}

void	deletenode()
{
//delete

}

int	ft_stri(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i])
		return (i);
	return (-1);
}
void	export(t_commandlist *mini)
{
	int	i;

	i = 1;
	if(mini->pipe)
		return ;
	while (mini->arguments[i])
	{
		if (ft_stri(mini->arguments[i], '=') == -1)
			special_case(mini);
		append_node(mini, ft_substr(mini->arguments[i], ft_stri(mini->arguments[i], '='), ft_strlen(mini->arguments[i])));
		i++;
	}
}
void	ft_pwd(t_commandlist *mini)
{
	printf("%s\n", getcwd(NULL, 42));
}

