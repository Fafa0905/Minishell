#include "minishell.h"

void free_args(t_arg *args)
{
    t_arg *tmp;

    tmp = args;
    while (tmp)
    {
        tmp = args->next;
        if (args->content)
        {
            printf("Libération d'argument -> Adresse : %p, Contenu : %p (%s)\n", (void *)args, (void *)args->content, args->content);
            free(args->content);
            args->content = NULL;
        }
        printf("Libération du noeud d'argument -> Adresse : %p\n", (void *)args);
        free(args);
        args = tmp;
    }
}

void free_command(t_command *cmd)
{
    t_command   *tmp;

    while (cmd)
    {
        tmp = cmd->next;
        if (cmd->args)
            free_args(cmd->args);
        if (cmd->infile)
            free_args(cmd->infile);
        if (cmd->outfile)
            free_args(cmd->outfile);
        if (cmd->append)
            free_args(cmd->append);
        if (cmd->heredoc)
            free_args(cmd->heredoc);
        printf("Libération de la commande -> Adresse : %p\n", (void *)cmd);
        free(cmd);
        cmd = tmp;
    }
}

void free_shell(t_commandlist *mini)
{
    t_token     *temp;
    t_token     *next_token;
    t_command   *temp_command;

    printf("freeshell\n");
    if (mini)
    {
        temp = mini->tokens;
        while (temp)
            {
                next_token = temp->next;
                printf("Libération du token -> Adresse : %p, Valeur : %p (%s), Type : %d\n", (void *)temp, (void *)temp->value, temp->value, temp->type);
                {
                    free(temp->value);
                    temp->value = NULL;
                }
                free(temp);
                temp = next_token;
            }
    }
    temp_command = mini->cmd;
    if (temp_command)
    {
        free_command(temp_command);
        printf("Toutes les commandes ont été libérées.\n");
        temp_command = NULL;
    }
    mini->cmd = NULL;
    mini->tokens = NULL;
    printf("Fin de la libération de MiniShell\n");
}

void    clean_up_and_exit(char *input, t_commandlist *mini)
{
    if (input)
        free(input);
    if (mini)
        free_shell(mini);
    free(mini);
    rl_clear_history();
    exit(0);
}