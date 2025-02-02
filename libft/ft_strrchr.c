/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:14:19 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 22:13:59 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*cc;
	char		a;

	cc = NULL;
	a = c;
	while (*s)
	{
		if (*s == a)
			cc = s;
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return ((char *)cc);
}
