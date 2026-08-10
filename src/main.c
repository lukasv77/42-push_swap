/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 13:45:41 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 15:45:01 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	int		*args_array;
	int		size;

	b = NULL;
	if (argc < 2)
		return (0);
	
	args_array = parse_arguments(argc, argv, &size);
	if (!args_array)
		return (1);
	a = create_a(args_array, size);
	free(args_array);
	bubble_sort(&a, &b);
	lst_printer(a);
	return (0);
}