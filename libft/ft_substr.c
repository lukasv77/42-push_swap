/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:51:19 by llinda            #+#    #+#             */
/*   Updated: 2026/06/23 14:26:40 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	rlen;
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, sizeof(char)));
	j = 0;
	rlen = ft_strlen(&s[start]);
	if (len <= rlen)
		ptr = malloc((len + 1) * sizeof(char));
	else
		ptr = malloc((rlen + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[start + j] && len)
	{
		ptr[j] = s[start + j];
		j++;
		len--;
	}
	ptr[j] = 0;
	return (ptr);
}

/* int	main(void)
{
	char	s1[] = "Hello Peers!";
	printf("%s\n%s\n", s1, ft_substr(s1, 6, 5));
} */