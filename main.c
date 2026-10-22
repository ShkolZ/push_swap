/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 04:22:25 by vbertych          #+#    #+#             */
/*   Updated: 2026/10/22 18:24:06 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cfg	c;

	c = parse_arguments(argc, argv);
	if (!prepare(&c))
		cfg_error(&c);
	if (c.stack.size)
	{
		if (c.mode == ADAPTIVE)
			choose_strategy(&c);
		run_sort(&c);
		if (c.is_bench)
			print_bench(c.bench);
	}
	clear_cfg(&c);
	return (0);
}
