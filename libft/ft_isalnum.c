/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:38:36 by llinda            #+#    #+#             */
/*   Updated: 2026/06/16 12:09:33 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main(void)
{
	char a = '1';
	char b = 'a';
	char c = ' ';
	printf("%c %c %c\n", a, b, c);
	printf("%d %d %d", ft_isalnum(a), ft_isalnum(b), ft_isalnum(c));
} */