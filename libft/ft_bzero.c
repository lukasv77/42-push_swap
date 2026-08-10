/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:24:20 by llinda            #+#    #+#             */
/*   Updated: 2026/06/30 16:17:48 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/* int	main(void)
{
	char	str[] = "Hello";
	int	len = 6;
	int	i = -1;

	ft_bzero(str, 4);
	while (++i < len)
	{
		printf(" %u |", str[i]);
	}
} */