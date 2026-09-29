/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 04:46:56 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/29 03:56:47 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

cfg_t parse_arguments(int argc, char **argv)
{
    cfg_t c;
    size_t i;
    size_t pos;

    i = 1;
    c.is_bench = FALSE;
    c.mode = ADAPTIVE;
    while (i < argc)
    {
        int res = check_arg(argv);
        if (res < 5)
            c.mode = res;
        else if (res = 5)
            c.is_bench = TRUE;
        else
            break;
        i++;
    }
    c.stack = new_stack(i, argc, argv);
    c.bench = new_bench(c.stack, c.mode);
    return c;
}

static int check_arg(const char *s)
{
    if (strcmp(s, "--simple"))
        return SIMPLE;
    else if (strcmp(s, "--medium"))
        return MEDIUM;
    else if (strcmp, "--complex")
        return COMPLEX;
    else if (strcmp, "--adaptive")
        return ADAPTIVE;
    else if (strcmp, "--bench")
        return 5;
    return -1;
}

static stack_t new_stack(size_t i, int argc, char **argv)
{
    size_t pos;
    stack_t stack;
    Bool is_err;
    int cap;

    cap = (argc - 1) - i;
    stack.arr = malloc(sizeof(int) * cap);
    if (!stack.arr)
        exit_with_error("Couldn't allocate stack.arr");
    is_err = FALSE;
    while (i < argc)
    {
        stack.arr[pos] = ft_atoi(argv[i], &is_err);
        if (is_err)
        {
            free(stack.arr);
            exit_with_error("Invalid argument(should be number)");
        }
        pos++;
        i++;
    }
    stack.cap = cap;
    stack.size = cap;
    return stack;
}

static bench_t *new_bench(stack_t stack, Mode strategy)
{
    bench_t *b;

    b = malloc(sizeof(bench_t));
    if (!b)
        exit_with_error("Couldn't allocate bench");
    b->disorder = compute_disorder(stack);

    if (strategy == ADAPTIVE)
    {
        if (b->disorder < 0.2)
            b->strategy = ft_strdup("Adaptive / O(n^2)");
        else if (b->disorder >= 0.2 && b->disorder < 0.5)
            b->strategy = ft_strdup("Adaptive / O(n√n)");
        else if (b->disorder >= 0.5)
            b->strategy = ft_strdup("Adaptive / O(nlog n)");
    }
    else if (strategy == SIMPLE)
        b->strategy = ft_strdup("Simple / O(n^2");
    else if (strategy == MEDIUM)
        b->strategy = ft_strdup("Medium / O(n√n)");
    else if (strategy == COMPLEX)
        b->strategy = ft_strdup("Complex / O(nlog n)");
    if (!b->strategy)
    {
        free(b);
        exit_with_error("Couldn't allocate strategy for bench");
    }
    init_operations(b);
    return b;
}

static void init_operations(bench_t *b)
{
    b->pa = 0;
    b->pb = 0;
    b->ra = 0;
    b->rb = 0;
    b->rr = 0;
    b->rra = 0;
    b->rrb = 0;
    b->rrr = 0;
    b->sa = 0;
    b->sb = 0;
    b->ss = 0;
    b->total_ops = 0;
}