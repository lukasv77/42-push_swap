/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:07:49 by llinda            #+#    #+#             */
/*   Updated: 2026/06/26 19:36:49 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nl;

	nl = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nl = -(long)n;
	}
	if (nl >= 10)
		ft_putnbr_fd(nl / 10, fd);
	c = nl % 10 + '0';
	write(fd, &c, 1);
}

/* int	main(void)
{
	int	n = -2147483648;

	ft_putnbr_fd(n, 1);
} */