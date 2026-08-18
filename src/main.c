/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:02:17 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/18 14:27:30 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // ./push_swap --simple --medium 3 2 1 5 4 3

/* static void	lst_printer(t_dlist *lst)
{
	t_dlist	*node;

	if (!lst)
		return ;
	node = lst;
	ft_printf("\n");
	while (1)
	{
		ft_printf("val: %i prev: %p next: %p\n", node->content, node->prev,
			node->next);
		if (node->next)
			node = node->next;
		if (node == lst)
			break ;
	}
	ft_printf("\n");
} */

static void	parse_flags(int *argc, char ***argv, t_stats *stats)
{
	(*argv)++;
	(*argc)--;
	stats->strategy = STRAT_ADAPTIVE;
	stats->bench = false;
	while ((*argc) > 1)
	{
		if (ft_strncmp((*argv)[0], "--simple", 9) == 0)
			stats->strategy = STRAT_SIMPLE;
		else if (ft_strncmp((*argv)[0], "--medium", 9) == 0)
			stats->strategy = STRAT_MEDIUM;
		else if (ft_strncmp((*argv)[0], "--complex", 10) == 0)
			stats->strategy = STRAT_COMPLEX;
		else if (ft_strncmp((*argv)[0], "--adaptive", 11) == 0)
			stats->strategy = STRAT_ADAPTIVE;
		else if (ft_strncmp((*argv)[0], "--bench", 8) == 0)
			stats->bench = true;
		else
			break ;
		(*argv)++;
		(*argc)--;
	}
}

static void	run_strategy(t_dlist **a, t_dlist **b, t_stats *stats)
{
	if (stats->strategy == STRAT_SIMPLE)
		insertion_sort(a, b, stats);
	else if (stats->strategy == STRAT_MEDIUM)
		medium_sort(a, b, stats);
	else if (stats->strategy == STRAT_COMPLEX)
		complex_sort(a, b, stats);
	else
	{
		if (stats->disorder < 20.0)
			insertion_sort(a, b, stats);
		else if (stats->disorder < 50.0)
			medium_sort(a, b, stats);
		else
			complex_sort(a, b, stats);
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	t_stats	stats;

	a = NULL;
	b = NULL;
	ft_bzero(&stats, sizeof(t_stats));
	parse_flags(&argc, &argv, &stats);
	if (argc < 2)
		return (0);
	if (!parse_arguments(argv, &a))
		return (1);
	stats.disorder = calculate_disorder_percentage(a);
	run_strategy(&a, &b, &stats);
	if (stats.bench)
		print_benchmark(&stats);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
