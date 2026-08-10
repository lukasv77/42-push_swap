/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:22:04 by llinda            #+#    #+#             */
/*   Updated: 2026/07/26 14:29:45 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_print_hexlower(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_print_hexupper(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1), 1);
	else
		return (-1);
}

int	ft_vprintf(const char *str, va_list args)
{
	size_t	i;
	int		counter;

	if (!str)
		return (-1);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i++], 1);
			counter++;
		}
		else
		{
			if (str[i + 1] == 0)
				return (-1);
			counter += handle_conversion(str[++i], args);
			i++;
		}
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		chars_nb;
	va_list	args;

	va_start(args, str);
	chars_nb = ft_vprintf(str, args);
	va_end(args);
	return (chars_nb);
}
