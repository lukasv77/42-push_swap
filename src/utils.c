/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:59:45 by username          #+#    #+#             */
/*   Updated: 2026/08/10 21:10:48 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	lst_printer(t_dlist *lst)
{
	t_dlist	*node;

	if (!lst)
		return ;
	node = lst;
	while (1)
	{
		printf("val: %i prev: %i next: %i\n",
			node->content, node->prev->content,
			node->next->content);
		if (node->next)
			node = node->next;
		if (node == lst)
			break ;
	}
	printf("\n\n");
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
