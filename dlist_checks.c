/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:48:05 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 15:53:32 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

bool	is_single_or_pair(t_dlist *node)
{
	return (node->next && node->prev && node->next == node->prev);
}

bool	is_in_circular_list(t_dlist *node)
{
	return (node->next && node->prev && node->next != node->prev);
}
