/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:22:13 by llinda            #+#    #+#             */
/*   Updated: 2026/06/17 22:21:00 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	int		len = 6;
	int		i = -1;
	char	dest[100];
	char	src[] = "Hello";

	ft_memcpy(dest, src, 3);
	while (++i < len)
	{
		printf(" %u |", src[i]);
	}
	i = -1;
	printf("\n");
	while (++i < len)
	{
		printf(" %u |", dest[i]);
	}
} */