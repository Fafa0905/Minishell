/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:15:54 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 22:11:33 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dd;
	char	*ss;
	size_t	i;

	ss = (char *)src;
	dd = (char *)dest;
	i = 0;
	if (!ss && !dd)
		return (NULL);
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dest);
}
