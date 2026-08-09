/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:59:45 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 11:48:15 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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
	(*node)->prev->next = (*node)->next;
	(*node)->next->prev = (*node)->prev;	
	old_head = *node;
	*node = (*node)->next;
	free(old_head);
}

t_dlist	*ft_dlstadd_back(t_data *data, t_dlist *new)
{
	if (!data || !new)
		return (NULL);
	if (!data->tail)
		data->tail = new;
	else
	{
		data->tail->next = new;
		new->prev = data->tail;
		data->tail = new;
	}
	return (new);
}

t_dlist	*ft_dlstadd_front(t_data *data, t_dlist *new)
{
	if (!data || !new)
		return (NULL);
	if (!data->head || !data->tail)
	{
		data->head = new;
		data->tail = new;
	}
	else
	{
		data->head->prev = new;
		new->next = data->head;
		data->head = new;
		new->prev = data->tail;
		data->tail->next = new;
	}
	return (new);
}

void	lst_printer(t_dlist *lst)
{
	bool	check;
	t_dlist	*node;

	if (!lst)
		return ;
	node = lst;
	check = false;
	while (check == false || node != lst)
	{
		printf("val: %i prev: %p next: %p\n", node->content, node->prev, node->next);
		if (node->next)
			node = node->next;
		check = true;
	}
	printf("\n\n");
}