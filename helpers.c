/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 03:48:02 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/29 04:05:29 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float compute_disorder(stack_t stack)
{
    float mistakes;
    float total_pairs;
    size_t i;
    size_t j;

    mistakes = 0;
    total_pairs = 0;
    i = 0;
    while (i < stack.size - 1)
    {
        j = i + 1;
        while (j < stack.size - 1)
        {
            total_pairs++;
            if (stack.arr[i] > stack.arr[j])
                mistakes++;
            j++;
        }
        i++;
    }
    return mistakes / total_pairs;
}

void choose_strategy(cfg_t *cfg)
{
    float dis;

    dis = cfg->bench->disorder;
    if (dis < 0.2)
        cfg->mode = SIMPLE;
    else if (dis >= 0.2 && dis < 0.5)
        cfg->mode = MEDIUM;
    else if (dis >= 0.5)
        cfg->mode = COMPLEX;
}

void print_bench(bench_t *bench)
{
}
