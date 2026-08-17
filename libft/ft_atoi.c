/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:55:44 by llinda            #+#    #+#             */
/*   Updated: 2026/06/30 17:22:04 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_longmax(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	char	*nbptr;
	long	sign;
	long	result;

	nbptr = (char *)nptr;
	sign = 1;
	result = 0;
	while ((*nbptr >= 9 && *nbptr <= 13) || *nbptr == ' ')
		nbptr++;
	if (*nbptr == '-')
	{
		sign = -sign;
		nbptr++;
	}
	else if (*nbptr == '+')
		nbptr++;
	while (*nbptr >= '0' && *nbptr <= '9')
	{
		if ((LONG_MAX / 10 < result)
			|| (LONG_MAX / 10 == result && LONG_MAX % 10 < *nbptr - '0'))
			return (ft_longmax(sign));
		result = result * 10 + *nbptr - '0';
		nbptr++;
	}
	return (result * sign);
}

/* int	main(void)
{
	char	str[] = "-99999999999999999999999";

	printf("%s\nft_atoi: %d\n", str, ft_atoi(str));
	printf("atoi:    %d\n", atoi(str));
} */