/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:13:09 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/10 12:37:52 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdbool.h>
# include <stddef.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

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
void	ra(t_dlist **a);
void	sa(t_dlist **a);
void	sb(t_dlist **b);
void	ss(t_dlist **a, t_dlist **b);
void	pa(t_dlist **a, t_dlist **b);
void	pb(t_dlist **a, t_dlist **b);
void	rb(t_dlist **b);
void	rr_both(t_dlist **a, t_dlist **b);
void	rra(t_dlist **a);
void	rrb(t_dlist **b);
void	rrr(t_dlist **a, t_dlist **b);
void	bubble_sort(t_dlist **a, t_dlist **b);
t_dlist	*create_a(int *args, int size);
bool	is_single_or_pair(t_dlist *node);
bool	is_in_circular_list(t_dlist *node);
t_dlist	*ft_dlstnew(int content);
void	ft_dlstdelone(t_dlist **node);
t_dlist	*ft_dlstadd_back(t_dlist **head, t_dlist *new);
t_dlist	*ft_dlstadd_front(t_dlist **head, t_dlist *new);
void	lst_printer(t_dlist *lst);
int	*parse_arguments(int argc, char **argv, int *total_size);
bool	is_valid_number(char *str);
int	ft_safe_atoi(char *str, int *error);
bool	has_duplicates(int *arr, int size);
// errors
void	ft_print_error(void);
void	free_split(char **split);
int		*ft_parse_error(char **args, int *arr, int argc);

#endif