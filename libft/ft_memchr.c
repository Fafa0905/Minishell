/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:31 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 23:59:19 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*mm;
	size_t				i;
	unsigned char		cc;

	mm = (unsigned const char *)s;
	i = 0;
	cc = c;
	while (i < n)
	{
		if (mm[i] == cc)
			return ((void *)(mm + i));
		i++;
	}
	return (NULL);
}
