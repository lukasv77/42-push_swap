/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:38:36 by llinda            #+#    #+#             */
/*   Updated: 2026/06/16 13:11:03 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main(void)
{
	char a = 128;
	char b = 'a';
	char c = '-';
	printf("%c %c %c\n", a, b, c);
	printf("%d %d %d", ft_isascii(a), ft_isascii(b), ft_isascii(c));
} */