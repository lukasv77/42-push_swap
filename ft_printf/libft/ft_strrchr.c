/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:16:32 by llinda            #+#    #+#             */
/*   Updated: 2026/06/18 15:01:11 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	i;
	size_t	len;
	char	ch;

	p = (char *)s;
	ch = (char) c;
	len = ft_strlen(p);
	i = len;
	if (ch == 0)
		return (&p[len]);
	while (i > 0)
	{
		i--;
		if (p[i] == ch)
			return (&p[i]);
	}
	return (0);
}

/* int	main(void)
{
	char	str[] = "Hello World! Hello Peers!";
	char	*ptr;
	char	*temp;

	ptr = ft_strrchr(str, 'l'); // << CHANGE ME!
	temp = str;
	printf("%s\n", str);
	while (temp < ptr)
	{
		printf(" ");
		temp++;
	}
	if (ptr != 0)
		printf("^\n");
	printf("%p", ptr);
} */