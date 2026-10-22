/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:11:33 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 18:24:06 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Retain the original entry point; sorting uses only permitted operations. */
t_stack	bubble_sort(t_cfg cfg)
{
	sort_simple(&cfg);
	return (cfg.stack);
}

void	run_sort(t_cfg *cfg)
{
	if (is_sorted(&cfg->stack))
		return ;
	if (cfg->stack.size <= 5)
		sort_small(cfg);
	else if (cfg->mode == SIMPLE)
		cfg->stack = bubble_sort(*cfg);
	else if (cfg->mode == MEDIUM)
		sort_medium(cfg);
	else
		sort_complex(cfg);
}
