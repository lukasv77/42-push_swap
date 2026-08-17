/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:38:36 by llinda            #+#    #+#             */
/*   Updated: 2026/06/16 13:46:08 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main(void)
{
	char a = '\0';
	char b = 'a';
	char c = '-';
	printf("%s %c %c\n", "\\0", b, c);
	printf("%d %d %d", ft_isprint(a), ft_isprint(b), ft_isprint(c));
} */