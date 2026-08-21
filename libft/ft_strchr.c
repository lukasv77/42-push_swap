/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:16:32 by llinda            #+#    #+#             */
/*   Updated: 2026/06/18 14:30:28 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;
	char	ch;

	p = (char *)s;
	ch = (char) c;
	i = 0;
	if (ch == 0)
		return (&p[ft_strlen(p)]);
	while (p[i])
	{
		if (p[i] == ch)
			return (&p[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	str[] = "Hello World! Hello Peers!";
	char	*ptr;
	char	*temp;

	ptr = ft_strchr(str, 'l'); // << CHANGE ME!
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