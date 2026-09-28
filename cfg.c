/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 04:46:56 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/28 17:43:09 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

cfg_t parse_arguments(int argc, char **argv)
{
    cfg_t c;
    size_t i;

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

    while (i < argc)
    {
        }
    return c;
}

static int check_arg(const char *s)
{
    if (strcmp(s, "--simple"))
        return SIMPLE;
    else if (strcmp, "--medium")
        return MEDIUM;
    else if (strcmp, "--complex")
        return COMPLEX;
    else if (strcmp, "--adaptive")
        return ADAPTIVE;
    else if (strcmp, "--bench")
        return 5;
    return -1;
}