/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:46:42 by vbertych          #+#    #+#             */
/*   Updated: 2026/10/22 18:23:28 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_bench *bench)
{
	stack_swap(a);
	record_op(bench, &bench->sa, "sa");
}

void	sb(t_stack *b, t_bench *bench)
{
	stack_swap(b);
	record_op(bench, &bench->sb, "sb");
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	stack_swap(a);
	stack_swap(b);
	record_op(bench, &bench->ss, "ss");
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	stack_push(a, b);
	record_op(bench, &bench->pa, "pa");
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	stack_push(b, a);
	record_op(bench, &bench->pb, "pb");
}
