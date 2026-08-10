/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:31:11 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 20:36:17 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_dlist **head)
{
	int	tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = tmp;
}

void	p(t_dlist **src, t_dlist **dst)
{
	if (!src || !*src)
		return ;
	*dst = ft_dlstadd_front(dst, ft_dlstnew((*src)->content));
	ft_dlstdelone(src);
}

void	r(t_dlist **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->next;
}

void	rr(t_dlist **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->prev;
}

void	ra(t_dlist **a, t_stats *stats)
{
	r(a);
	ft_printf("ra\n");
	if (stats)
	{
		stats->ra++;
		stats->total_ops++;
	}
}