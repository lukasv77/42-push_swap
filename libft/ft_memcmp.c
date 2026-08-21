/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:01:25 by llinda            #+#    #+#             */
/*   Updated: 2026/06/20 13:09:59 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	size_t			i;

	i = 0;
	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (mem1[i] != mem2[i])
			return (mem1[i] - mem2[i]);
		i++;
	}
	return (0);
}

/* int main(void)
{
	char s1[] = "Hello\0World!";
	char s2[] = "Hello\0W0rld!";

	printf("%s\n%s\nft_memcmp: %d\n", s1, s2, ft_memcmp(s1, s2, 0));
	printf("%s\n%s\nmemcmp: %d\n", s1, s2, memcmp(s1, s2, 0));
} */