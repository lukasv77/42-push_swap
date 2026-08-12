/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:13:09 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/12 17:23:38 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_stats
{
	t_strategy	strategy;
	bool		bench;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	int			total_ops;
	double		disorder;
}	t_stats;

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

// Operations and core functions
void	ra(t_dlist **a, t_stats *stats);
void	sa(t_dlist **a, t_stats *stats);
void	sb(t_dlist **b, t_stats *stats);
void	ss(t_dlist **a, t_dlist **b, t_stats *stats);
void	pa(t_dlist **a, t_dlist **b, t_stats *stats);
void	pb(t_dlist **a, t_dlist **b, t_stats *stats);
void	rb(t_dlist **b, t_stats *stats);
void	rr_both(t_dlist **a, t_dlist **b, t_stats *stats);
void	rra(t_dlist **a, t_stats *stats);
void	rrb(t_dlist **b, t_stats *stats);
void	rrr(t_dlist **a, t_dlist **b, t_stats *stats);
bool	s(t_dlist **head);
bool	p(t_dlist **src, t_dlist **dst);
bool	r(t_dlist **head);
bool	rr(t_dlist **head);
void	bubble_sort(t_dlist **a, t_dlist **b, t_stats *stats);
void	medium_sort(t_dlist **a, t_dlist **b, t_stats *stats);
void	complex_sort(t_dlist **a, t_dlist **b, t_stats *stats);

// List utilities and checks
t_dlist	*ft_dlstnew(int content);
void	ft_dlstdelone(t_dlist **node);
t_dlist	*ft_dlstadd_back(t_dlist **head, t_dlist *new);
t_dlist	*ft_dlstadd_front(t_dlist **head, t_dlist *new);
int		ft_dlstsize(t_dlist *lst);
void	free_stack(t_dlist **head);

// Parsing and Errors
bool	parse_arguments(char **argv, t_dlist **stack_a);
bool	is_valid_number(char *str);
int		ft_safe_atoi(char *str, int *error);
void	ft_print_error(void);
void	free_split(char **split);

// Disorder and Benchmark
int		get_disorder_metric(t_dlist *lst);
double	calculate_disorder_percentage(t_dlist *lst);
void	print_benchmark(t_stats *stats);

#endif