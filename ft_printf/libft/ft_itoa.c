/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:26:11 by llinda            #+#    #+#             */
/*   Updated: 2026/06/23 13:09:40 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;
	long	l_n;

	len = 1;
	l_n = n;
	if (l_n < 0)
	{
		len++;
		l_n = -l_n;
	}
	while (l_n >= 10)
	{
		len++;
		l_n /= 10;
	}
	return (len);
}

static char	*ft_itoa_recursive(char *ptr, long n)
{
	if (n >= 10)
		ptr = ft_itoa_recursive(ptr, n / 10);
	*ptr = n % 10 + '0';
	return (++ptr);
}

char	*ft_itoa(int n)
{
	long	l_n;
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_intlen(n);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		*ptr = '-';
		i++;
		l_n = -(long)n;
	}
	else
		l_n = n;
	ft_itoa_recursive(&ptr[i], l_n);
	ptr[len] = 0;
	return (ptr);
}

/* int	main(void)
{
	int	n = -2147483648;

	printf("%s", ft_itoa(n));
} */