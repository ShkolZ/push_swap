/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:10:54 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 19:00:02 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_at(t_stack *s, size_t index)
{
	return (s->arr[s->size - index - 1]);
}

int	is_sorted(t_stack *s)
{
	size_t	i;

	i = 1;
	while (i < s->size)
	{
		if (stack_at(s, i - 1) > stack_at(s, i))
			return (0);
		i++;
	}
	return (1);
}

size_t	index_max(t_stack *s)
{
	size_t	i;
	size_t	best;

	i = 0;
	best = 0;
	while (++i < s->size)
		if (stack_at(s, i) > stack_at(s, best))
			best = i;
	return (best);
}

void	bring_top(t_cfg *c, size_t index, int on_b)
{
	size_t	n;
	size_t	steps;
	int		op;

	n = c->stack.size;
	if (on_b)
		n = c->b.size;
	op = RA + on_b;
	steps = index;
	if (index > n / 2)
	{
		op = RRA + on_b;
		steps = n - index;
	}
	while (steps-- > 0)
		operate(c, op);
}
