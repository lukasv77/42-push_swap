/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:04:34 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/11 08:04:34 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder_percentage(t_dlist *lst)
{
	int		size;
	int		inv;
	double	total_pairs;

	size = ft_dlstsize(lst);
	if (size <= 1)
		return (0.0);
	inv = get_disorder_metric(lst);
	total_pairs = (double)(size * (size - 1)) / 2.0;
	if (total_pairs == 0.0)
		return (0.0);
	return (((double)inv / total_pairs) * 100.0);
}

static void	print_disorder_fd(double disorder, int fd)
{
	int	int_part;
	int	dec_part;

	int_part = (int)disorder;
	dec_part = (int)((disorder - int_part) * 100 + 0.5);
	if (dec_part >= 100)
	{
		int_part++;
		dec_part -= 100;
	}
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(int_part, fd);
	write(fd, ".", 1);
	if (dec_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(dec_part, fd);
	ft_putstr_fd("%\n", fd);
}

static void	print_strategy_and_ops(t_stats *stats)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (stats->strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple /  O(n²)\n", 2);
	else if (stats->strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (stats->strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		if (stats->disorder < 20.0)
			ft_putstr_fd("Adaptive / O(n²)\n", 2);
		else if (stats->disorder < 50.0)
			ft_putstr_fd("Adaptive / O(n√n)\n", 2);
		else
			ft_putstr_fd("Adaptive / O(n log n)\n", 2);
	}
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(stats->total_ops, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_op_counts(t_stats *stats)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(stats->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(stats->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(stats->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(stats->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(stats->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(stats->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(stats->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(stats->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(stats->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(stats->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(stats->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_stats *stats)
{
	print_disorder_fd(stats->disorder, 2);
	print_strategy_and_ops(stats);
	print_op_counts(stats);
}
