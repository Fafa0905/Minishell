/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:54:40 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/04 22:16:13 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include"libft.h"

int	lenint(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len ++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = lenint(nb);
	str = (char *) malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while ((len -- > 0))
	{
		if (str[len] == '-')
			break ;
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
