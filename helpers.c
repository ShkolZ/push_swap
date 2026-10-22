/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 03:48:02 by vbertych          #+#    #+#             */
/*   Updated: 2026/10/22 18:36:08 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack stack)
{
	unsigned long long	mistakes;
	size_t				i;
	size_t				j;
	double				total_pairs;

	if (stack.size < 2)
		return (0.0);
	mistakes = 0;
	i = 0;
	while (i < stack.size)
	{
		j = i + 1;
		while (j < stack.size)
		{
			if (stack_at(&stack, i) > stack_at(&stack, j))
				mistakes++;
			j++;
		}
		i++;
	}
	total_pairs = (double)stack.size * (stack.size - 1) / 2;
	return (mistakes / total_pairs);
}

void	choose_strategy(t_cfg *cfg)
{
	if (cfg->bench->disorder < 0.2)
		cfg->mode = SIMPLE;
	else if (cfg->bench->disorder < 0.5)
		cfg->mode = MEDIUM;
	else
		cfg->mode = COMPLEX;
}

static int	rank_stack(t_cfg *cfg)
{
	size_t	i;
	size_t	j;
	int		rank;

	i = 0;
	while (i < cfg->stack.size)
	{
		j = 0;
		rank = 0;
		while (j < cfg->stack.size)
		{
			if (i != j && cfg->stack.arr[i] == cfg->stack.arr[j])
				return (0);
			if (cfg->stack.arr[j] < cfg->stack.arr[i])
				rank++;
			j++;
		}
		cfg->b.arr[i] = rank;
		i++;
	}
	return (1);
}

int	prepare(t_cfg *cfg)
{
	size_t	i;

	if (!rank_stack(cfg))
		return (0);
	i = 0;
	while (i < cfg->stack.size)
	{
		cfg->stack.arr[i] = cfg->b.arr[i];
		i++;
	}
	return (1);
}
