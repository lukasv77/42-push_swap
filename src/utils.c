/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:59:45 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 15:47:19 by llinda           ###   ########.fr       */
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
		printf("val: %i prev: %i next: %i\n", node->content, node->prev->content,
			node->next->content);
		if (node->next)
			node = node->next;
		if (node == lst)
			break ;
	}
	printf("\n\n");
}
