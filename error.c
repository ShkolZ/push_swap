/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 02:50:00 by vbertych          #+#    #+#             */
/*   Updated: 2026/09/29 02:52:05 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exit_with_error(const char *err)
{
    if (!err)
        ft_printf("Error\n");
    else
        ft_printf(err);
    exit(1);
}