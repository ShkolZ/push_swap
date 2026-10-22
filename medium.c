/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:55:42 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 18:59:48 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	extract_chunk(t_cfg *c, int low, int high)
{
	int		left;
	size_t	steps;
	size_t	rotations;

	left = high - low;
	steps = c->stack.size;
	rotations = 0;
	while (steps-- > 0 && left > 0)
	{
		if (stack_at(&c->stack, 0) >= low && stack_at(&c->stack, 0) < high)
		{
			operate(c, PB);
			left--;
		}
		else
		{
			operate(c, RA);
			rotations++;
		}
	}
	if (c->stack.size)
		bring_top(c, (c->stack.size - rotations % c->stack.size)
			% c->stack.size, 0);
}

void	sort_medium(t_cfg *c)
{
	int	width;
	int	high;
	int	low;

	width = 1;
	while (width < (int)c->stack.cap / width)
		width++;
	width *= 2;
	high = (int)c->stack.cap;
	while (high > 0)
	{
		low = high - width;
		if (low < 0)
			low = 0;
		extract_chunk(c, low, high);
		while (c->b.size)
		{
			bring_top(c, index_max(&c->b), 1);
			operate(c, PA);
		}
		high = low;
	}
}
