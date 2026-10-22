/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:52:44 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 18:59:48 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_cfg *c)
{
	int		bit;
	size_t	steps;

	bit = 0;
	while (((unsigned int)(c->stack.cap - 1) >> bit) != 0)
	{
		steps = c->stack.size;
		while (steps-- > 0)
		{
			if (((unsigned int)stack_at(&c->stack, 0) >> bit) & 1)
				operate(c, RA);
			else
				operate(c, PB);
		}
		while (c->b.size)
			operate(c, PA);
		bit++;
	}
}
