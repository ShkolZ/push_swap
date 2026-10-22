/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:58:55 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 17:58:56 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_fd(const char *s, int fd)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	write(fd, s, n);
}

void	putnum_fd(size_t n, int fd)
{
	char	ch;

	if (n >= 10)
		putnum_fd(n / 10, fd);
	ch = '0' + n % 10;
	write(fd, &ch, 1);
}
