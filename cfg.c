/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 04:46:56 by vbertych          #+#    #+#             */
/*   Updated: 2026/10/22 18:45:48 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	equal(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

static int	check_arg(const char *s)
{
	if (equal(s, "--simple"))
		return (SIMPLE);
	if (equal(s, "--medium"))
		return (MEDIUM);
	if (equal(s, "--complex"))
		return (COMPLEX);
	if (equal(s, "--adaptive"))
		return (ADAPTIVE);
	if (equal(s, "--bench"))
		return (4);
	return (-1);
}

static void	read_flags(t_cfg *c, int argc, char **argv)
{
	int		i;
	int		flag;
	t_bool	has_mode;

	has_mode = FALSE;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-' || argv[i][1] != '-')
		{
			if (!parse_tokens(argv[i], &c->stack, FALSE))
				cfg_error(c);
			continue ;
		}
		flag = check_arg(argv[i]);
		if (flag < 0 || (flag == 4 && c->is_bench)
			|| (flag != 4 && has_mode))
			cfg_error(c);
		c->is_bench = c->is_bench || flag == 4;
		has_mode = has_mode || flag != 4;
		if (flag != 4)
			c->mode = (t_mode)flag;
	}
}

static void	new_stacks(t_cfg *c, int argc, char **argv)
{
	int	i;

	c->stack.cap = c->stack.size;
	c->b.cap = c->stack.cap;
	if (!c->stack.cap)
		return ;
	c->stack.arr = malloc(c->stack.cap * sizeof(int));
	c->b.arr = malloc(c->b.cap * sizeof(int));
	if (!c->stack.arr || !c->b.arr)
		cfg_error(c);
	c->stack.size = 0;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			continue ;
		if (!parse_tokens(argv[i], &c->stack, TRUE))
			cfg_error(c);
	}
}

t_cfg	parse_arguments(int argc, char **argv)
{
	t_cfg	c;

	c = (t_cfg){0};
	c.mode = ADAPTIVE;
	read_flags(&c, argc, argv);
	new_stacks(&c, argc, argv);
	c.bench = malloc(sizeof(t_bench));
	if (!c.bench)
		cfg_error(&c);
	*c.bench = (t_bench){0};
	c.bench->disorder = compute_disorder(c.stack);
	init_bench(&c);
	return (c);
}
