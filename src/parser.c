/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:00:00 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/10 16:00:00 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static char	**get_args(int argc, char **argv, int *size)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			free_split(args);
			return (NULL);
		}
		*size = count_split(args);
	}
	else
	{
		args = argv + 1;
		*size = argc - 1;
	}
	return (args);
}

static int	*process_args(char **args, int size, int argc)
{
	int	*arr;
	int	i;
	int	error;

	error = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size && !error)
	{
		if (!is_valid_number(args[i]))
			error = 1;
		else
			arr[i] = ft_safe_atoi(args[i], &error);
		i++;
	}
	if (error || has_duplicates(arr, size))
		return (ft_parse_error(args, arr, argc));
	return (arr);
}

int	*parse_arguments(int argc, char **argv, int *total_size)
{
	char	**args;
	int		*arr;

	args = get_args(argc, argv, total_size);
	if (!args)
	{
		ft_print_error();
		return (NULL);
	}
	arr = process_args(args, *total_size, argc);
	if (!arr)
		return (NULL);
	if (argc == 2)
		free_split(args);
	return (arr);
}