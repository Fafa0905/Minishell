/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrtunsnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:39:12 by ssoukoun          #+#    #+#             */
/*   Updated: 2025/01/12 12:46:02 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	intelen(unsigned long n)
{
	int				count;
	unsigned long	nb;

	count = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_wrtunsnbr_fd(unsigned long n, int fd)
{
	int		count;
	long	nb;

	nb = n;
	count = intelen(nb);
	if (nb > 9)
		ft_wrtunsnbr_fd(nb / 10, fd);
	ft_wrtchar_fd((nb % 10) + '0', fd);
	return (count);
}
