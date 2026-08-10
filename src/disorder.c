/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:00:00 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 16:00:00 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:00:00 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 16:00:00 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlstsize(t_dlist *lst)
{
	int		size;
	t_dlist	*curr;

	if (!lst)
		return (0);
	size = 0;
	curr = lst;
	while (1)
	{
		size++;
		curr = curr->next;
		if (curr == lst)
			break ;
	}
	return (size);
}

int	get_disorder_metric(t_dlist *lst)
{
	int		inv;
	t_dlist	*i_node;
	t_dlist	*j_node;

	if (!lst || lst->next == lst)
		return (0);
	inv = 0;
	i_node = lst;
	while (1)
	{
		j_node = i_node->next;
		while (j_node != lst)
		{
			if (i_node->content > j_node->content)
				inv++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
		if (i_node == lst)
			break ;
	}
	return (inv);
}