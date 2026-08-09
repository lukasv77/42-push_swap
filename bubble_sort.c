/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:33:06 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 15:45:26 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static size_t	bubble_pass(t_dlist **a, t_dlist *first)
{
	size_t	swap_cnt;

	swap_cnt = 0;
	while (1)
	{
		if ((*a)->content > (*a)->next->content)
		{
			s(a);
			swap_cnt++;
		}
		r(a);
		if ((*a)->next == first)
			break ;
	}
	return (swap_cnt);
}

static void	restore_stack(t_dlist **a, t_dlist **b)
{
	r(a);
	while (*b)
	{
		p(b, a);
		r(a);
	}
}

void	bubble_sort(t_dlist **a, t_dlist **b)
{
	size_t	swap_cnt;
	t_dlist	*first;

	first = *a;
	swap_cnt = 1;
	while (swap_cnt > 0)
	{
		swap_cnt = bubble_pass(a, first);
		if (swap_cnt != 0)
			p(a, b);
		else
			restore_stack(a, b);
	}
}
