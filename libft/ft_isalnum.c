/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:58:01 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 23:59:00 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'A') && c <= 'Z')
		return (1);
	else if ((c >= 'a') && c <= 'z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
