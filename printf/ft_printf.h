/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:35:19 by ssoukoun          #+#    #+#             */
/*   Updated: 2025/01/06 11:15:09 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_printex(unsigned long nb, char symbol);
int	ft_wrtchar_fd(int c, int fd);
int	ft_wrtnbr_fd(int n, int fd);
int	ft_wrtunsnbr_fd(unsigned long n, int fd);
int	ft_wrtstr_fd(const char *s, int fd);
int	ft_ptr(long long a);

#endif
