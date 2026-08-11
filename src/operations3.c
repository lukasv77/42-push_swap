/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations3.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/11 08:01:56 by username         #+#    #+#              */
/*   Updated: 2026/08/11 12:53:18 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_dlist **b, t_stats *stats)
{
	if (r(b))
	{
		ft_printf("rb\n");
		if (stats)
		{
			stats->rb++;
			stats->total_ops++;
		}
	}
}

void	rr_both(t_dlist **a, t_dlist **b, t_stats *stats)
{
	if (r(a) && r(b))
	{
		ft_printf("rr\n");
		if (stats)
		{
			stats->rr++;
			stats->total_ops++;
		}
	}
}

void	rra(t_dlist **a, t_stats *stats)
{
	if (rr(a))
	{
		ft_printf("rra\n");
		if (stats)
		{
			stats->rra++;
			stats->total_ops++;
		}
	}
}

void	rrb(t_dlist **b, t_stats *stats)
{
	if (rr(b))
	{
		ft_printf("rrb\n");
		if (stats)
		{
			stats->rrb++;
			stats->total_ops++;
		}
	}
}

void	rrr(t_dlist **a, t_dlist **b, t_stats *stats)
{
	if (rr(a) && rr(b))
	{
		ft_printf("rrr\n");
		if (stats)
		{
			stats->rrr++;
			stats->total_ops++;
		}
	}
}
