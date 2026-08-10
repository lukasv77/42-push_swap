/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:33:06 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 20:52:03 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	bubble_pass(t_dlist **a, t_dlist *first, t_stats *stats)
{
	size_t	swap_cnt;

	swap_cnt = 0;
	while (1)
	{
		if ((*a)->content > (*a)->next->content)
		{
			sa(a, stats);
			swap_cnt++;
		}
		ra(a, stats);
		if ((*a)->next == first)
			break ;
	}
	return (swap_cnt);
}

static void	restore_stack(t_dlist **a, t_dlist **b, t_stats *stats)
{
	ra(a, stats);
	while (*b)
	{
		pa(a, b, stats);
		ra(a, stats);
	}
}

void	bubble_sort(t_dlist **a, t_dlist **b, t_stats *stats)
{
	size_t	swap_cnt;
	t_dlist	*first;

	first = *a;
	swap_cnt = 1;
	while (swap_cnt > 0)
	{
		swap_cnt = bubble_pass(a, first, stats);
		if (swap_cnt != 0)
			pb(a, b, stats);
		else
			restore_stack(a, b, stats);
	}
}
