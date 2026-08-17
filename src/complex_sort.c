/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:49:39 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/12 17:40:00 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	if (max_bits == 0)
		max_bits = 1;
	return (max_bits);
}

static int	get_rank(t_dlist *a, t_dlist *b, int val)
{
	t_dlist	*curr;
	int		rank;
	int		size;
	int		i;

	rank = 0;
	size = ft_dlstsize(a);
	curr = a;
	i = 0;
	while (i++ < size)
	{
		if (curr->content < val)
			rank++;
		curr = curr->next;
	}
	size = ft_dlstsize(b);
	curr = b;
	i = 0;
	while (i++ < size)
	{
		if (curr->content < val)
			rank++;
		curr = curr->next;
	}
	return (rank);
}

static void	push_back_to_a(t_dlist **a, t_dlist **b, t_stats *stats)
{
	while (ft_dlstsize(*b) > 0)
		pa(a, b, stats);
}

static void	radix_pass(t_dlist **a, t_dlist **b, int bit, t_stats *stats)
{
	int	j;
	int	size;
	int	rank;

	size = ft_dlstsize(*a);
	j = 0;
	while (j < size)
	{
		rank = get_rank(*a, *b, (*a)->content);
		if (((rank >> bit) & 1) == 0)
			pb(a, b, stats);
		else
			ra(a, stats);
		j++;
	}
	push_back_to_a(a, b, stats);
}

void	complex_sort(t_dlist **a, t_dlist **b, t_stats *stats)
{
	int	size;
	int	max_bits;
	int	i;

	if (!a || !*a)
		return ;
	size = ft_dlstsize(*a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, i, stats);
		i++;
	}
}
