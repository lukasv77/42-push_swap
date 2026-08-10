/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:31:11 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 15:43:48 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_dlist **head)
{
	int	tmp;

	tmp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = tmp;
}

void	p(t_dlist **src, t_dlist **dst)
{
	*dst = ft_dlstadd_front(dst, ft_dlstnew((*src)->content));
	ft_dlstdelone(src);
}

void	r(t_dlist **head)
{
	*head = (*head)->next;
}

void	rr(t_dlist **head)
{
	*head = (*head)->prev;
}

void	ra(t_dlist **a)
{
	r(a);
	ft_printf("ra\n");
}