/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:22:24 by llinda            #+#    #+#             */
/*   Updated: 2026/06/22 14:20:54 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	if (!s1[0])
		return (ft_calloc(1, sizeof(char)));
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (end < start)
		return (ft_calloc(1, sizeof(char)));
	return (ft_substr(s1, start, end - start + 1));
}

/* int	main(void)
{
	char	s1[] = "cba Hello Peers! bac";
	char	s2[] = "abc ";

	printf("%s\n%s\n%s\n", s1, s2, ft_strtrim(s1, s2));
} */