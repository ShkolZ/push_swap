/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 04:22:25 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/28 17:43:11 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    cfg_t c;

    if (argc < 2)
        return 0;
    c = parse_arguments(argc, argv);
}