/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:44:19 by ssoukoun          #+#    #+#             */
/*   Updated: 2025/02/02 18:41:06 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


typedef enum tolkien
{
    NO_DEF,
    CMD,
    PIPE,
    QUOTE,
    D_QUOTE,
    DOLLAR,
    IN,
    D_IN,
    OUT,
    D_OUT
};

typedef struct part
{
	tolkien     type;
    char        *part;
}				t_p;

typedef struct mini
{
	char		*pieces

}				t_mini;

#endif