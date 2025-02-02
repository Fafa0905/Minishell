/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:32:38 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 22:13:23 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*c;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	c = malloc((i + 1) * sizeof(const char));
	if (c == NULL)
		return (NULL);
	while (j < i)
	{
		c[j] = (*f)(j, s[j]);
		j++;
	}
	c[j] = '\0';
	return (c);
}
