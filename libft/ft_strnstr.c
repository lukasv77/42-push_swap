/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 12:37:47 by llinda            #+#    #+#             */
/*   Updated: 2026/07/01 10:44:01 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	i = 0;
	little_len = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	if (len < little_len)
		return (0);
	while (big[i] && i + little_len <= len)
	{
		if (!(ft_strncmp(&big[i], little, little_len)))
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char str[] = "";
	char word[] = "";
	char *ptr;
	char *ptrorg;
	char *temp;

	ptr = ft_strnstr(str, word, strlen(str));
	temp = str;
	printf("%s\n", str);
	while (temp < ptr)
	{
		printf(" ");
		temp++;
	}
	if (ptr != 0)
		printf("^\n");
	printf("ft_strnstr: %p\n", ptr);

	ptrorg = strnstr(str, word, strlen(str));
	printf("strnstr:    %p\n", ptrorg);
} */