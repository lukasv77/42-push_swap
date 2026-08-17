/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:22:13 by llinda            #+#    #+#             */
/*   Updated: 2026/06/18 08:47:37 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n != 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

/* int	main(void)
{
	int		i = -1;
//	char	dest[100];
	char	src[] = "        Hello World! :)         ";
	int		len = ft_strlen(src) + 1;

	printf("%s\n", src);
	while (++i < len)
	{
		printf(" %u |", src[i]);
	}
	printf("\n");
	ft_memmove(&src[24], &src[8], 6);
//	ft_memmove(src, &src[8], 6);
	printf("%s\n", src);
	i = -1;
	while (++i < len)
	{
		printf(" %u |", src[i]);
	}
} */