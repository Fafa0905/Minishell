/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:32:04 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 22:07:24 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ss;
	size_t	i;

	ss = (char *)s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
}
