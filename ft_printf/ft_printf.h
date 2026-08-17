/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:24:11 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 15:21:45 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
int		ft_fd_printf(int fd, const char *str, ...);
int		handle_conversion(char c, va_list args);
size_t	ft_print_str(char *s, int fd);
int		ft_print_nbr(int n, int fd);
int		ft_print_unsigned(unsigned int n, int fd);
int		ft_vprintf(const char *str, va_list args);
int		ft_print_hexlower(unsigned int n, int fd);
int		ft_print_hexupper(unsigned int n, int fd);
int		ft_print_ptr(void *ptr, int fd);

#endif
