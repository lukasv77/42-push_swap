/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:27:24 by llinda            #+#    #+#             */
/*   Updated: 2026/08/17 20:00:09 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_dlist **a, t_dlist **b, t_stats *stats)
{
	int	key;
	t_dlist	*node;
	size_t	last_higher_pos;
	size_t	size_b;

	key = (*a)->content;
	node = *b;
	last_higher_pos = 0;
	if (*b == NULL)
		pb(a, b, stats);
	while (node->content > key)
	{
		node = node->next;
		last_higher_pos++;
	}
	size_b = ft_dlstsize(*b);
	if (size_b - last_higher_pos >= last_higher_pos)
	{
		while (last_higher_pos--)
			rb(b, stats);
	}
	else
	{
		while (last_higher_pos--)
			rrb(b, stats);
	}
	pb(a, b, stats);
	while (*b)
	{
		pa(a, b, stats)
	}
}