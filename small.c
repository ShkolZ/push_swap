/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:10:40 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 19:00:02 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_cfg *c)
{
	size_t	max;

	max = index_max(&c->stack);
	if (max == 0)
		operate(c, RA);
	else if (max == 1)
		operate(c, RRA);
	if (stack_at(&c->stack, 0) > stack_at(&c->stack, 1))
		operate(c, SA);
}

static size_t	index_min(t_stack *s)
{
	size_t	i;
	size_t	best;

	i = 0;
	best = 0;
	while (++i < s->size)
		if (stack_at(s, i) < stack_at(s, best))
			best = i;
	return (best);
}

void	sort_small(t_cfg *c)
{
	while (c->stack.size > 3)
	{
		bring_top(c, index_min(&c->stack), 0);
		operate(c, PB);
	}
	if (c->stack.size == 3)
		sort_three(c);
	else if (c->stack.size == 2
		&& stack_at(&c->stack, 0) > stack_at(&c->stack, 1))
		operate(c, SA);
	while (c->b.size)
		operate(c, PA);
}

void	sort_simple(t_cfg *c)
{
	while (c->stack.size > 3)
	{
		bring_top(c, index_min(&c->stack), 0);
		operate(c, PB);
	}
	sort_small(c);
}
