/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:00:00 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/10 16:00:00 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	*ft_parse_error(char **args, int *arr, int argc)
{
	if (arr)
		free(arr);
	if (argc == 2 && args)
		free_split(args);
	ft_print_error();
	return (NULL);
}