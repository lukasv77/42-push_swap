/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 13:45:41 by llinda            #+#    #+#             */
/*   Updated: 2026/08/10 20:28:17 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char **parse_flags(int *argc, char **argv, t_stats *stats)
{
    stats->strategy = STRAT_ADAPTIVE;
    stats->bench = false;
    while (*argc > 1)
    {
        if (ft_strncmp(argv[1], "--simple", 9) == 0)
            stats->strategy = STRAT_SIMPLE;
        else if (ft_strncmp(argv[1], "--medium", 9) == 0)
            stats->strategy = STRAT_MEDIUM;
        else if (ft_strncmp(argv[1], "--complex", 10) == 0)
            stats->strategy = STRAT_COMPLEX;
        else if (ft_strncmp(argv[1], "--adaptive", 11) == 0)
            stats->strategy = STRAT_ADAPTIVE;
        else if (ft_strncmp(argv[1], "--bench", 8) == 0)
            stats->bench = true;
        else
            break ;
        argv++;
        (*argc)--;
    }
    return (argv);
}

static void	run_strategy(t_dlist **a, t_dlist **b, t_stats *stats)
{
    if (stats->strategy == STRAT_SIMPLE)
        bubble_sort(a, b, stats);
    else if (stats->strategy == STRAT_MEDIUM)
        bubble_sort(a, b, stats);
    else if (stats->strategy == STRAT_COMPLEX)
        bubble_sort(a, b, stats);
    else
    {
        if (stats->disorder < 20.0)
            bubble_sort(a, b, stats);
        else if (stats->disorder < 50.0)
            bubble_sort(a, b, stats);
        else
            bubble_sort(a, b, stats);
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
    argv = parse_flags(&argc, argv, &stats);
    if (argc < 2)
        return (0);
    if (!parse_arguments(argc, argv, &a))
        return (1);
    stats.disorder = calculate_disorder_percentage(a);
    run_strategy(&a, &b, &stats);
    if (stats.bench)
        print_benchmark(&stats);
    free_stack(&a);
    free_stack(&b);
    return (0);
}