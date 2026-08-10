/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:18:18 by llinda            #+#    #+#             */
/*   Updated: 2026/07/01 14:41:08 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i])
		i++;
	dst_len = i;
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst_len + src_len);
}

/* int	main(void)
{
	char	src[] = " Hello World!";
	char	dst[10000] = "Hello Peer";
	char	dst2[10000] = "Hello Peer";

	printf("Total length of the string tried to create: %ld\n%s\n%s\n",
		ft_strlcat(dst, src, 11), src, dst);
	printf("Total length of the string tried to create: %ld\n%s\n%s\n",
		strlcat(dst2, src, 11), src, dst);
} */