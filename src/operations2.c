/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations2.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/11 08:02:03 by username         #+#    #+#              */
/*   Updated: 2026/08/11 12:53:00 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dlist **a, t_stats *stats)
{
	if (s(a))
	{
		ft_printf("sa\n");
		if (stats)
		{
			stats->sa++;
			stats->total_ops++;
		}
	}
}

void	sb(t_dlist **b, t_stats *stats)
{
	if (s(b))
	{
		ft_printf("sb\n");
		if (stats)
		{
			stats->sb++;
			stats->total_ops++;
		}
	}
}

void	ss(t_dlist **a, t_dlist **b, t_stats *stats)
{
	if (s(a) && s(b))
	{
		ft_printf("ss\n");
		if (stats)
		{
			stats->ss++;
			stats->total_ops++;
		}
	}
}

void	pa(t_dlist **a, t_dlist **b, t_stats *stats)
{
	if (p(b, a))
	{
		ft_printf("pa\n");
		if (stats)
		{
			stats->pa++;
			stats->total_ops++;
		}
	}
}

void	pb(t_dlist **a, t_dlist **b, t_stats *stats)
{
	if (p(a, b))
	{
		ft_printf("pb\n");
		if (stats)
		{
			stats->pb++;
			stats->total_ops++;
		}
	}
}
