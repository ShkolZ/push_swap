/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:46:42 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/28 21:00:27 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(stack_t *a, bench_t *bench)
{
    int tmp;
    if (a->size < 1)
        return;
    tmp = a->arr[a->size - 1];
    a->arr[a->size - 1] = a->arr[a->size - 2];
    a->arr[a->size - 2] = tmp;
    ft_printf("sa\n");
    bench->total_ops += 1;
    bench->sa += 1;
}
void sb(stack_t *b, bench_t *bench)
{
    int tmp;
    if (b->size < 1)
        return;
    tmp = b->arr[b->size - 1];
    b->arr[b->size - 1] = b->arr[b->size - 2];
    b->arr[b->size - 2] = tmp;
    ft_printf("sb\n");
    bench->total_ops += 1;
    bench->sb += 1;
}
void ss(stack_t *a, stack_t *b, bench_t *bench)
{
    sa(a, bench);
    sb(b, bench);
}
void pa(stack_t *a, stack_t *b, bench_t *bench)
{
    if (b->size == 0)
        return;
    if (a->size + 1 > b->cap)
        return;
    a->arr[a->size] = b->arr[b->size - 1];
    b->size -= 1;
    a->size += 1;
    ft_printf("pa\n");
    bench->total_ops += 1;
    bench->pa += 1;
}
void pb(stack_t *a, stack_t *b, bench_t *bench)
{
    if (a->size == 0)
        return;
    if (b->size + 1 > b->cap)
        return;
    b->arr[b->size] = a->arr[a->size - 1];
    a->size -= 1;
    b->size += 1;
    ft_printf("pb\n");
    bench->total_ops += 1;
    bench->pb += 1;
}