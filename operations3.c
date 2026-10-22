/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:57:44 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 19:00:14 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	stack_reverse(a);
	stack_reverse(b);
	record_op(bench, &bench->rrr, "rrr");
}

void	record_op(t_bench *bench, size_t *counter, const char *name)
{
	(*counter)++;
	bench->total_ops++;
	putstr_fd(name, 1);
	write(1, "\n", 1);
}

const char	*op_name(int op)
{
	const char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	return (names[op]);
}

void	operate(t_cfg *c, int op)
{
	if (op == SA)
		sa(&c->stack, c->bench);
	else if (op == SB)
		sb(&c->b, c->bench);
	else if (op == SS)
		ss(&c->stack, &c->b, c->bench);
	else if (op == PA)
		pa(&c->stack, &c->b, c->bench);
	else if (op == PB)
		pb(&c->stack, &c->b, c->bench);
	else if (op == RA)
		ra(&c->stack, c->bench);
	else if (op == RB)
		rb(&c->b, c->bench);
	else if (op == RR)
		rr(&c->stack, &c->b, c->bench);
	else if (op == RRA)
		rra(&c->stack, c->bench);
	else if (op == RRB)
		rrb(&c->b, c->bench);
	else if (op == RRR)
		rrr(&c->stack, &c->b, c->bench);
}
