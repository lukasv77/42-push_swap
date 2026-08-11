/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:00:48 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/11 08:00:48 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	has_duplicate(t_dlist *head, int value)
{
	t_dlist	*current;

	if (!head)
		return (false);
	current = head;
	while (1)
	{
		if (current->content == value)
			return (true);
		current = current->next;
		if (current == head)
			break ;
	}
	return (false);
}

static bool	append_node(t_dlist **stack_a, char *arg)
{
	int		value;
	int		error;
	t_dlist	*node;

	error = 0;
	if (!is_valid_number(arg))
		return (false);
	value = ft_safe_atoi(arg, &error);
	if (error || has_duplicate(*stack_a, value))
		return (false);
	node = ft_dlstnew(value);
	if (!node)
		return (false);
	if (!ft_dlstadd_back(stack_a, node))
		return (false);
	return (true);
}

static bool	get_args(char **argv, char ***args, int *allocated)
{
	if (argv[0] && argv[1] == NULL && ft_strchr(argv[0], ' '))
	{
		*args = ft_split(argv[0], ' ');
		if (!*args || !(*args)[0])
		{
			if (*args)
				free_split(*args);
			return (false);
		}
		*allocated = 1;
	}
	else
	{
		*args = argv;
		*allocated = 0;
	}
	return (true);
}

static bool	fill_stack(char **args, t_dlist **stack_a)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!append_node(stack_a, args[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	parse_arguments(char **argv, t_dlist **stack_a)
{
	char	**args;
	int		allocated;
	bool	success;

	allocated = 0;
	args = NULL;
	if (!get_args(argv, &args, &allocated))
		return (ft_print_error(), false);
	success = fill_stack(args, stack_a);
	if (allocated)
		free_split(args);
	if (!success)
		return (free_stack(stack_a), ft_print_error(), false);
	return (true);
}
