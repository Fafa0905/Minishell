/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:10:18 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 23:59:27 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ss;
	unsigned const char	*sss;
	size_t				i;

	ss = (unsigned const char *)s1;
	sss = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss[i] != sss[i])
			return (ss[i] - sss[i]);
		i++;
	}
	return (0);
}
