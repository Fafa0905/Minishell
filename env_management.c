#include "minishell.h"

void	lux(t_commandlist *mini)
{
	char **tab;
	int	i;
	int	j;
	
	i = 1;
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
	t_lst	*cur;

	i = 0;
	cur = (*mini->env);
	tab = ft_strtrim(tab, "\"");
	while (cur)
	{
		line = ft_strnstr(cur->line, (tab+ 1), ft_strlen(tab));
		if (line)
			return (ft_strdup(cur->line + ft_strlen(tab) + 1));
		cur = cur->next;
	}
	return (tab);
}

void	set_env(t_commandlist *mini, char **env)
{
	int	i;

	i = 0;
	if (!env)
		(printf("YArien a gratter \n"), exit(0));
	mini->env = malloc(sizeof(t_lst *));
	if (mini->env == NULL)
    	return ;
	*mini->env = NULL;
	while (env[i])
	{
		append_node(mini, env[i]);
		i++;
	}
	printf("%i\n", i);
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
	//if (newnode)
	//	printf("la ligne est : %s\n",newnode->line);
	if (*mini->env == NULL)
	{
		*mini->env = newnode;
		newnode->pre = NULL;
	}
	else
	{
		last = find_last(*mini->env);
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
	if (ft_strncmp(mini->arguments[0], "exit", ft_strlen("exit")) == 0)
		ft_exit(mini);
	if (ft_strncmp(mini->arguments[0], "echo", ft_strlen("echo")) == 0)
		ft_echo(mini);
	if (ft_strncmp(mini->arguments[0], "env", ft_strlen("env")) == 0)
		ft_env(mini);
	if (ft_strncmp(mini->arguments[0], "unset", ft_strlen("unset")) == 0)
		ft_unset(mini);
	if (ft_strncmp(mini->arguments[0], "export", ft_strlen("export")) == 0)
		ft_export(mini);
	if (ft_strncmp(mini->arguments[0], "pwd", ft_strlen("pwd")) == 0)
		ft_pwd(mini);
	if (ft_strncmp(mini->arguments[0], "cd", ft_strlen("cd")) == 0)
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
	
	i = 1;
	while (mini->arguments[i])
	{
		printf("%s\n",  mini->arguments[i]);
		i++;
	}
}
void	ft_env(t_commandlist *mini)
{
	t_lst	*cur;

	cur = (*mini->env);
	while(cur)
	{
		printf("%s \n", cur->line);
		cur = cur->next;
	}
}
void ft_unset(t_commandlist *mini)
{
    int j;
    t_lst *cur;
    t_lst *del;
    t_lst *prev;

    cur = *mini->env;
    while (cur)
    {
        j = 1;
        while (mini->arguments[j])
        {
            if (ft_strncmp(cur->line, mini->arguments[j], ft_strlen(mini->arguments[j])) == 0)
            {
                del = cur;
                cur = cur->next;
                if (del == *mini->env)
                    *mini->env = cur;
                if (prev)
                {
                    prev->next = cur;
                    if (cur)
                        cur->pre = prev;
                }
                deletenode(del);
                j = -1;
                break;
            }
            j++;
        }
        prev = cur;
        if (j != -1)
            cur = cur->next;
    }
}


void deletenode(t_lst *out)
{
    if (!out)  // Vérifie si out est NULL
    {
        printf("Erreur : nœud invalide\n");
        return ;
    }
    // Si le nœud a un prédecesseur
    if (out->pre)
    {
        // Si le nœud a un successeur
        if (out->next)
        {
            out->pre->next = out->next;
            out->next->pre = out->pre;
        }
        // Si le nœud est le dernier de la liste
        else
            out->pre->next = NULL;
    }
    // Si le nœud n'a pas de prédecesseur, il est le premier nœud
    else if (out->next)
        out->next->pre = NULL;
    // Finalement, réinitialiser le nœud
    out->pre = NULL;
    out->next = NULL;
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
void	ft_export(t_commandlist *mini)
{
	int	i;

	i = 1;
	if(mini->pipe)
		return ;
	while (mini->arguments[i])
	{
		if (ft_stri(mini->arguments[i], '=') == -1)
			return ;
			//special_case(mini);
		append_node(mini, ft_substr(mini->arguments[i], 0, ft_strlen(mini->arguments[i])));
		i++;
	}
}
void	ft_pwd(t_commandlist *mini)
{
	(void)mini;
	printf("%s\n", getcwd(NULL, 42));
}

void	ft_cd(t_commandlist *mini)
{
	if (mini->arguments[2])
		printf("too many arguments\n");
	if (chdir(mini->arguments[1]) == -1)
		printf("directory problem\n");
}
