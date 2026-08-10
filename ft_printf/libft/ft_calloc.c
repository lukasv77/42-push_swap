/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:19:31 by llinda            #+#    #+#             */
/*   Updated: 2026/06/30 11:07:20 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*tmp;
	size_t	total_size;

	if (size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	if (total_size / size != nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	tmp = (char *)ptr;
	while (total_size > 0)
	{
		*tmp = 0;
		tmp++;
		total_size--;
	}
	return (ptr);
}

/* int	main(void)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_calloc(50, 4);
	printf("%p\n", ptr);
	while (i < 200)
	{
		printf("%d", ptr[i]);
		i++;
	}
} */
