#include "minishell.h"

void    free_shell(t_commandlist *mini)
{
    printf("freeshell\n");
    if (mini)
        if (mini->arguments)
            free_split(mini->arguments);
}

void    free_split(char **split)
{
    int i;

    i = 0;
    if (!split)
        return;
    while (split[i])
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

void    clean_up_and_exit(char *input, t_commandlist *mini)
{
    if (input)
        free(input);
    if (mini)
        free_shell(mini);
    rl_clear_history();
    exit(0);
}
