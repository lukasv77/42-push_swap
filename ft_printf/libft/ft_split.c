/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:44 by llinda            #+#    #+#             */
/*   Updated: 2026/06/30 16:53:29 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	if (s[i] && s[i] != c)
	{
		nb++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			nb++;
		i++;
	}
	return (nb);
}

static void	*ft_freemem(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
	return (NULL);
}

static char	**alloc_word(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = malloc(ft_wordlen(&s[i], c) + 1 * sizeof(char));
			if (!arr[j])
				return (ft_freemem(arr));
			ft_strlcpy(arr[j], &s[i], ft_wordlen(&s[i], c) + 1);
			while (s[i] != c && s[i])
				i++;
			j++;
		}
		else
			i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = ft_calloc(ft_wordcounter(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (alloc_word(s, c, arr));
}

/* int	main(void)
{
	char	s1[] = "  Hello   World Hello Peers!   ";
	char	c = ' ';
	char	**arr;

	printf("%s\n", s1);
	arr = ft_split(s1, c);
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
} */