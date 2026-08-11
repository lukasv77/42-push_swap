/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:01:56 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/11 08:01:56 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_dlist **b, t_stats *stats)
{
	r(b);
	ft_printf("rb\n");
	if (stats)
	{
		stats->rb++;
		stats->total_ops++;
	}
}

void	rr_both(t_dlist **a, t_dlist **b, t_stats *stats)
{
	r(a);
	r(b);
	ft_printf("rr\n");
	if (stats)
	{
		stats->rr++;
		stats->total_ops++;
	}
}

void	rra(t_dlist **a, t_stats *stats)
{
	rr(a);
	ft_printf("rra\n");
	if (stats)
	{
		stats->rra++;
		stats->total_ops++;
	}
}

void	rrb(t_dlist **b, t_stats *stats)
{
	rr(b);
	ft_printf("rrb\n");
	if (stats)
	{
		stats->rrb++;
		stats->total_ops++;
	}
}

void	rrr(t_dlist **a, t_dlist **b, t_stats *stats)
{
	rr(a);
	rr(b);
	ft_printf("rrr\n");
	if (stats)
	{
		stats->rrr++;
		stats->total_ops++;
	}
}
