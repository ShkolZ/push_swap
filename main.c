/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 04:22:25 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/29 03:54:49 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    cfg_t c;
    stack_t sorted;

    if (argc < 2)
        return 0;
    c = parse_arguments(argc, argv);

    if (c.mode == ADAPTIVE)
        choose_strategy(&c);
    if (c.mode == SIMPLE)
        sorted = bubble_sort(c);
    // else if(c.mode == MEDIUM)
    //     // Some algo to sort medium
    // else if (c.mode == COMPLEX)
    //     // Some algo to sort complex

    if (c.is_bench)
        print_bench(c.bench);
    print_stack(sorted);
}