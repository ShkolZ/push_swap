/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 02:50:00 by vbertych          #+#    #+#             */
/*   Updated: 2026/10/22 18:24:06 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_cfg(t_cfg *cfg)
{
	free(cfg->stack.arr);
	free(cfg->b.arr);
	free(cfg->bench);
	cfg->stack.arr = NULL;
	cfg->b.arr = NULL;
	cfg->bench = NULL;
}

void	exit_with_error(const char *err)
{
	(void)err;
	putstr_fd("Error\n", 2);
	exit(1);
}

void	cfg_error(t_cfg *cfg)
{
	clear_cfg(cfg);
	exit_with_error(NULL);
}
