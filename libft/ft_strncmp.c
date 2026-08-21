/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:01:25 by llinda            #+#    #+#             */
/*   Updated: 2026/06/20 14:21:03 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && n--)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* int main(void)
{
	char s1[] = "Hello World!";
	char s2[] = "3ello World!";

	printf("%s\n%s\nft_strncmp: %d\n", s1, s2, ft_strncmp(s1, s2, 1));
	printf("%s\n%s\nstrncmp: %d\n", s1, s2, strncmp(s1, s2, 1));
} */