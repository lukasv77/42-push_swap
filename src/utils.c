/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:59:45 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/17 22:40:48 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*create_a(int *args, int size)
{
	int		i;
	t_dlist	*head;

	head = NULL;
	i = -1;
	while (++i < size)
		ft_dlstadd_back(&head, ft_dlstnew(args[i]));
	return (head);
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
