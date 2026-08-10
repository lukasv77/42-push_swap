/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:31:11 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 20:00:00 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dlist **a, t_stats *stats)
{
	s(a);
	ft_printf("sa\n");
	if (stats)
	{
		stats->sa++;
		stats->total_ops++;
	}
}

void	sb(t_dlist **b, t_stats *stats)
{
	s(b);
	ft_printf("sb\n");
	if (stats)
	{
		stats->sb++;
		stats->total_ops++;
	}
}

void	ss(t_dlist **a, t_dlist **b, t_stats *stats)
{
	s(a);
	s(b);
	ft_printf("ss\n");
	if (stats)
	{
		stats->ss++;
		stats->total_ops++;
	}
}

void	pa(t_dlist **a, t_dlist **b, t_stats *stats)
{
	p(b, a);
	ft_printf("pa\n");
	if (stats)
	{
		stats->pa++;
		stats->total_ops++;
	}
}

void	pb(t_dlist **a, t_dlist **b, t_stats *stats)
{
	p(a, b);
	ft_printf("pb\n");
	if (stats)
	{
		stats->pb++;
		stats->total_ops++;
	}
}