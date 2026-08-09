/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:35:34 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 15:47:58 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_dlstdelone(t_dlist **node)
{
	t_dlist	*old_head;

	if (!node)
		return ;
	if (is_single_or_pair(*node))
	{
		(*node)->prev->next = NULL;
		(*node)->next->prev = NULL;
	}
	else if (is_in_circular_list(*node))
	{
		(*node)->prev->next = (*node)->next;
		(*node)->next->prev = (*node)->prev;
	}
	else
	{
		old_head = *node;
		*node = NULL;
		return (free(old_head));
	}
	old_head = *node;
	*node = (*node)->next;
	free(old_head);
}

t_dlist	*ft_dlstadd_back(t_dlist **head, t_dlist *new)
{
	if (!head || !new)
		return (NULL);
	if (!*head)
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return (new);
	}
	new->next = *head;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	(*head)->prev = new;
	return (new);
}

t_dlist	*ft_dlstadd_front(t_dlist **head, t_dlist *new)
{
	ft_dlstadd_back(head, new);
	*head = new;
	return (new);
}
