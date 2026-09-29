/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:00:56 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/28 21:32:52 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(stack_t *a, bench_t *bench)
{
    size_t i;
    int tmp;

    if (a->size < 2)
        return FALSE;
    i = a->size - 1;
    while (i > 0)
    {
        tmp = a->arr[i];
        a->arr[i] = a->arr[i - 1];
        a->arr[i - 1] = tmp;
        i--;
    }
    ft_printf("ra\n");
    bench->total_ops += 1;
    bench->ra += 1;
}
void rb(stack_t *b, bench_t *bench)
{
    size_t i;
    int tmp;

    if (b->size < 2)
        return FALSE;
    i = b->size - 1;
    while (i > 0)
    {
        tmp = b->arr[i];
        b->arr[i] = b->arr[i - 1];
        b->arr[i - 1] = tmp;
        i--;
    }
    ft_printf("rb\n");
    bench->total_ops += 1;
    bench->rb += 1;
}
void rr(stack_t *a, stack_t *b, bench_t *bench)
{
    ra(a, bench);
    rb(b, bench);
}
void rra(stack_t *a, bench_t *bench)
{
    size_t i;
    int tmp;

    i = 0;
    while (i < a->size - 1)
    {
        tmp = a->arr[i];
        a->arr[i] = a->arr[i + 1];
        a->arr[i + 1] = tmp;
        i++;
    }

    ft_printf("rra\n");
    bench->rra += 1;
    bench->total_ops += 1;
}
void rrb(stack_t *b, bench_t *bench)
{
    size_t i;
    int tmp;

    i = 0;
    while (i < b->size - 1)
    {
        tmp = b->arr[i];
        b->arr[i] = b->arr[i + 1];
        b->arr[i + 1] = tmp;
        i++;
    }

    ft_printf("rrb\n");
    bench->rrb += 1;
    bench->total_ops += 1;
}

void rrr(stack_t *a, stack_t *b, bench_t *bench)
{
    rra(a, bench);
    rrb(a, bench);
}