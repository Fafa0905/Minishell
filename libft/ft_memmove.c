/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:52:55 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 22:24:45 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dd;
	unsigned const char	*ss;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	ss = (unsigned char *)src;
	dd = (unsigned char *)dst;
	if (dd > ss)
	{
		i = len;
		while (i-- > 0)
		{
			dd[i] = ss[i];
		}
	}
	else
	{
		ft_memcpy(dd, ss, len);
	}
	return (dst);
}
