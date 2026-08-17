/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:02:10 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/11 12:56:22 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	s(t_dlist **head)
{
	int	tmp;

	if (!head || !*head || !(*head)->next || (*head)->next == *head)
		return (false);
	tmp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = tmp;
	return (true);
}

bool	p(t_dlist **src, t_dlist **dst)
{
	t_dlist	*node;

	if (!src || !*src || !dst)
		return (false);
	node = ft_dlstnew((*src)->content);
	if (!node)
		return (false);
	if (!ft_dlstadd_front(dst, node))
	{
		free(node);
		return (false);
	}
	ft_dlstdelone(src);
	return (true);
}

bool	r(t_dlist **head)
{
	if (!head || !*head || (*head)->next == *head)
		return (false);
	*head = (*head)->next;
	return (true);
}

bool	rr(t_dlist **head)
{
	if (!head || !*head || (*head)->prev == *head)
		return (false);
	*head = (*head)->prev;
	return (true);
}

void	ra(t_dlist **a, t_stats *stats)
{
	if (r(a))
	{
		ft_printf("ra\n");
		if (stats)
		{
			stats->ra++;
			stats->total_ops++;
		}
	}
}
