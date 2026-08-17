/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:27:24 by llinda            #+#    #+#             */
/*   Updated: 2026/08/17 23:07:17 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_to_pos(t_dlist **b, t_stats *stats, size_t pos)
{
	size_t	size;

	size = ft_dlstsize(*b);
	if (size - pos >= pos)
	{
		while (pos--)
			rb(b, stats);
	}
	else
	{
		while (pos++ < size)
			rrb(b, stats);
	}
}

void	insertion_sort(t_dlist **a, t_dlist **b, t_stats *stats)
{
	t_dlist	*node;
	size_t	pos;
	size_t	size;

	while (ft_dlstsize(*a) > 0)
	{
		node = *b;
		size = ft_dlstsize(*b);
		pos = 0;
		while (pos < size && node->content > (*a)->content)
		{
			node = node->next;
			pos++;
		}
		rotate_b_to_pos(b, stats, pos);
		pb(a, b, stats);
		while (pos--)
			rrb(b, stats);
	}
	while (*b)
		pa(a, b, stats);
}
