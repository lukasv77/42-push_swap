/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 00:40:19 by llinda            #+#    #+#             */
/*   Updated: 2026/07/25 12:01:47 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

size_t	ft_print_str(char *s, int fd)
{
	size_t	len;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

int	ft_print_nbr(int n, int fd)
{
	char	c;
	long	nl;
	int		counter;

	nl = n;
	counter = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		nl = -(long)n;
		counter++;
	}
	if (nl >= 10)
		counter += ft_print_nbr(nl / 10, fd);
	c = nl % 10 + '0';
	write(fd, &c, 1);
	return (counter);
}

int	ft_print_unsigned(unsigned int n, int fd)
{
	char	c;
	int		counter;

	counter = 1;
	if (n >= 10)
		counter = ft_print_unsigned(n / 10, fd) + 1;
	c = n % 10 + '0';
	write(fd, &c, 1);
	return (counter);
}

int	ft_print_hexlower(unsigned int n, int fd)
{
	char	c;
	int		counter;
	char	*base;

	base = "0123456789abcdef";
	counter = 1;
	if (n >= 16)
		counter += ft_print_hexlower(n / 16, fd);
	c = base[n % 16];
	write(fd, &c, 1);
	return (counter);
}

int	ft_print_hexupper(unsigned int n, int fd)
{
	char	c;
	int		counter;
	char	*base;

	base = "0123456789ABCDEF";
	counter = 1;
	if (n >= 16)
		counter += ft_print_hexupper(n / 16, fd);
	c = base[n % 16];
	write(fd, &c, 1);
	return (counter);
}
