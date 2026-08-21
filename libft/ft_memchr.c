/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:01:25 by llinda            #+#    #+#             */
/*   Updated: 2026/06/20 13:08:22 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	ch;
	size_t			i;

	i = 0;
	mem = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (mem[i] == ch)
			return (&mem[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	mem[] = "Hello World! Hello Peers!";
	char	*ptr;
	char	*ptrorg;
	char	*temp;
	char	c;

	c = '\0'; // << CHANGE ME!
	ptr = ft_memchr(mem, c, 26);
	ptrorg = memchr(mem, c, 26);
	temp = mem;
	printf("%s\n", mem);
	while (temp < ptr)
	{
		printf(" ");
		temp++;
	}
	if (ptr != 0)
		printf("^\n");
	printf("ft_memchr: %p\n", ptr);
	printf("memchr:    %p\n", ptrorg);
} */