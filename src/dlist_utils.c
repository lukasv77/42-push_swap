/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:35:34 by llinda            #+#    #+#             */
/*   Updated: 2026/08/11 13:11:53 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (!node || !*node)
		return ;
	old_head = *node;
	if (old_head->next == old_head)
	{
		*node = NULL;
	}
	else
	{
		old_head->prev->next = old_head->next;
		old_head->next->prev = old_head->prev;
		*node = old_head->next;
	}
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
	*head = new;
	return (new);
}
