/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsingh <fsingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:57:40 by fsingh            #+#    #+#             */
/*   Updated: 2025/02/04 17:58:05 by fsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int isspace(char c)
{
	if (c && (c == ' ' || c == '\n' || c == '\r' || c == '\f' || c == '\t' \
	|| c == '\v'))
        return (1);
    return (0);
}

int is_special(char *str)
{
    if (str && *str && ft_strlen(str) >= 2)
    {
        if (!ft_strncmp(str, ">>", 2))
            return (D_OUT);
        if (!ft_strncmp(str, "<<", 2))
            return (HEREDOC);
    }
    if (*str && ft_strlen(str) >= 1)
    {
        if (!ft_strncmp(str, "<", 1))
            return (IN);
        if (!ft_strncmp(str, ">", 1))
            return (OUT);
        if (!ft_strncmp(str, "|", 1))
            return (PIPE);
    }
    return (0);
}