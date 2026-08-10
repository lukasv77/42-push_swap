/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:00:00 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/10 20:30:00 by mmankows         ###   ########.fr       */
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

static bool	process_args(char **args, t_dlist **stack_a)
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

static bool	get_args(int argc, char **argv, char ***args, int *allocated)
{
    if (argc == 2)
    {
        *args = ft_split(argv[1], ' ');
        if (!*args || !(*args)[0])
        {
            if (*args)
                free_split(*args);
            return (false);
        }
        *allocated = 1;
        return (true);
    }
    *args = argv + 1;
    *allocated = 0;
    return (true);
}

void	free_stack(t_dlist **head)
{
    t_dlist	*current;
    t_dlist	*next;
    int		size;

    if (!head || !*head)
        return ;
    size = ft_dlstsize(*head);
    current = *head;
    while (size > 0)
    {
        next = current->next;
        free(current);
        current = next;
        size--;
    }
    *head = NULL;
}

bool	parse_arguments(int argc, char **argv, t_dlist **stack_a)
{
    char	**args;
    int		allocated;
    bool	success;

    allocated = 0;
    args = NULL;
    if (!get_args(argc, argv, &args, &allocated))
    {
        ft_print_error();
        return (false);
    }
    success = process_args(args, stack_a);
    if (allocated)
        free_split(args);
    if (!success)
    {
        free_stack(stack_a);
        ft_print_error();
    }
    return (success);
}