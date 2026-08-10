/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 00:40:19 by llinda            #+#    #+#             */
/*   Updated: 2026/07/11 13:46:44 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_ptr(void *ptr, int fd)
{
	char				c;
	unsigned long long	llptr;
	int					counter;
	char				*base;

	if (!ptr)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	base = "0123456789abcdef";
	llptr = (unsigned long long) ptr;
	counter = 1;
	if (llptr >= 16)
		counter += ft_print_ptr((void *)(llptr / 16), fd);
	else
	{
		write(fd, "0x", 2);
		counter += 2;
	}
	c = base[llptr % 16];
	write(fd, &c, 1);
	return (counter);
}
