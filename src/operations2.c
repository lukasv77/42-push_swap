/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:31:11 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 16:00:00 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dlist **a)
{
	s(a);
	ft_printf("sa\n");
}

void	sb(t_dlist **b)
{
	s(b);
	ft_printf("sb\n");
}

void	ss(t_dlist **a, t_dlist **b)
{
	s(a);
	s(b);
	ft_printf("ss\n");
}

void	pa(t_dlist **a, t_dlist **b)
{
	p(b, a);
	ft_printf("pa\n");
}

void	pb(t_dlist **a, t_dlist **b)
{
	p(a, b);
	ft_printf("pb\n");
}


