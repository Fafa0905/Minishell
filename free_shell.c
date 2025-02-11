#include "minishell.h"

void    free_shell(t_commandlist *mini)
{
    printf("freeshell\n");
    if (mini)
    {
        if (mini->arguments)
        {
            free_split(mini->arguments, -1);
        }
    }
}

void    free_split(char **split, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        if (split[i])
        {
            free(split[i]);
            split[i] = NULL;
        }
        i++;
    }
    free(split);
    split = NULL;
}

void clean_up_and_exit(char *input, t_commandlist *mini)
{
    if (input)
        free(input);
    free_shell(mini);
    exit(0);
}