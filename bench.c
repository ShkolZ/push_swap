/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:51:55 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 18:24:06 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*strategy_name(t_mode mode, t_bool adaptive)
{
	if (mode == SIMPLE && adaptive)
		return ("adaptive / simple O(n^2)");
	if (mode == MEDIUM && adaptive)
		return ("adaptive / medium O(n*sqrt(n))");
	if (mode == COMPLEX && adaptive)
		return ("adaptive / complex O(n*log(n))");
	if (mode == SIMPLE)
		return ("simple O(n^2)");
	if (mode == MEDIUM)
		return ("medium O(n*sqrt(n))");
	return ("complex O(n*log(n))");
}

void	init_bench(t_cfg *cfg)
{
	t_mode	requested;

	requested = cfg->mode;
	if (requested == ADAPTIVE)
		choose_strategy(cfg);
	cfg->bench->strategy = strategy_name(cfg->mode, requested == ADAPTIVE);
	cfg->mode = requested;
}

static void	print_metric(const char *name, size_t value)
{
	putstr_fd("[bench] ", 2);
	putstr_fd(name, 2);
	putstr_fd(": ", 2);
	putnum_fd(value, 2);
	write(2, "\n", 1);
}

void	print_bench(t_bench *b)
{
	size_t	percent;

	percent = (size_t)(b->disorder * 10000.0 + 0.5);
	putstr_fd("[bench] disorder: ", 2);
	putnum_fd(percent / 100, 2);
	write(2, ".", 1);
	if (percent % 100 < 10)
		write(2, "0", 1);
	putnum_fd(percent % 100, 2);
	putstr_fd("%\n[bench] strategy: ", 2);
	putstr_fd(b->strategy, 2);
	write(2, "\n", 1);
	print_metric("total_ops", b->total_ops);
	print_metric("sa", b->sa);
	print_metric("sb", b->sb);
	print_metric("ss", b->ss);
	print_metric("pa", b->pa);
	print_metric("pb", b->pb);
	print_metric("ra", b->ra);
	print_metric("rb", b->rb);
	print_metric("rr", b->rr);
	print_metric("rra", b->rra);
	print_metric("rrb", b->rrb);
	print_metric("rrr", b->rrr);
}
