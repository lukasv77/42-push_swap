/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:04:36 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 16:01:27 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

void	s(t_dlist **head);
void	p(t_dlist **a, t_dlist **b);
void	r(t_dlist **head);
void	rr(t_dlist **head);
void	bubble_sort(t_dlist **a, t_dlist **b);
t_dlist	*create_a(int *args, int size);
bool	is_single_or_pair(t_dlist *node);
bool	is_in_circular_list(t_dlist *node);
t_dlist	*ft_dlstnew(int content);
void	ft_dlstdelone(t_dlist **node);
t_dlist	*ft_dlstadd_back(t_dlist **head, t_dlist *new);
t_dlist	*ft_dlstadd_front(t_dlist **head, t_dlist *new);
void	lst_printer(t_dlist *lst);

#endif