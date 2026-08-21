/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:49:39 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/12 17:10:00 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
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

static int	get_max_pos(t_dlist *b)
{
	int		max_val;
	int		max_pos;
	int		pos;
	int		size;
	t_dlist	*curr;

	size = ft_dlstsize(b);
	if (size == 0 || !b)
		return (0);
	max_val = b->content;
	max_pos = 0;
	pos = 0;
	curr = b;
	while (pos < size)
	{
		if (curr->content > max_val)
		{
			max_val = curr->content;
			max_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (max_pos);
}

static void	chunk_loop(t_dlist **a, t_dlist **b, int chunk, t_stats *stats)
{
	int	i;
	int	size;
	int	rank;

	i = 0;
	size = ft_dlstsize(*a);
	while (size > 0)
	{
		rank = get_rank(*a, *b, (*a)->content);
		if (rank <= i)
		{
			pb(a, b, stats);
			rb(b, stats);
			i++;
			size--;
		}
		else if (rank <= i + chunk)
		{
			pb(a, b, stats);
			i++;
			size--;
		}
		else
			ra(a, stats);
	}
}

void	medium_sort(t_dlist **a, t_dlist **b, t_stats *stats)
{
	int	size;
	int	chunk_size;
	int	max_pos;

	if (!a || !*a)
		return ;
	size = ft_dlstsize(*a);
	chunk_size = ft_isqrt(size);
	if (chunk_size < 1)
		chunk_size = 1;
	chunk_loop(a, b, chunk_size, stats);
	while (ft_dlstsize(*b) > 0)
	{
		max_pos = get_max_pos(*b);
		size = ft_dlstsize(*b);
		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				rb(b, stats);
		else
			while (max_pos++ < size)
				rrb(b, stats);
		pa(a, b, stats);
	}
}
