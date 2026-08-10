/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:31:11 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 16:00:00 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_dlist **b)
{
	r(b);
	ft_printf("rb\n");
}

void	rr_both(t_dlist **a, t_dlist **b)
{
	r(a);
	r(b);
	ft_printf("rr\n");
}

void	rra(t_dlist **a)
{
	rr(a);
	ft_printf("rra\n");
}

void	rrb(t_dlist **b)
{
	rr(b);
	ft_printf("rrb\n");
}

void	rrr(t_dlist **a, t_dlist **b)
{
	rr(a);
	rr(b);
	ft_printf("rrr\n");
}