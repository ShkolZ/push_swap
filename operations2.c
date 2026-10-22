/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:00:56 by vbertych          #+#    #+#             */
/*   Updated: 2026/10/22 18:23:28 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_bench *bench)
{
	stack_rotate(a);
	record_op(bench, &bench->ra, "ra");
}

void	rb(t_stack *b, t_bench *bench)
{
	stack_rotate(b);
	record_op(bench, &bench->rb, "rb");
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	stack_rotate(a);
	stack_rotate(b);
	record_op(bench, &bench->rr, "rr");
}

void	rra(t_stack *a, t_bench *bench)
{
	stack_reverse(a);
	record_op(bench, &bench->rra, "rra");
}

void	rrb(t_stack *b, t_bench *bench)
{
	stack_reverse(b);
	record_op(bench, &bench->rrb, "rrb");
}
