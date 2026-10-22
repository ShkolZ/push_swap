/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:12:22 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 18:23:04 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->arr[s->size - 1];
	s->arr[s->size - 1] = s->arr[s->size - 2];
	s->arr[s->size - 2] = tmp;
}

void	stack_push(t_stack *dst, t_stack *src)
{
	if (!src->size || dst->size >= dst->cap)
		return ;
	dst->arr[dst->size++] = src->arr[--src->size];
}

void	stack_rotate(t_stack *s)
{
	size_t	i;
	int		top;

	if (s->size < 2)
		return ;
	top = s->arr[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = top;
}

void	stack_reverse(t_stack *s)
{
	size_t	i;
	int		bottom;

	if (s->size < 2)
		return ;
	bottom = s->arr[0];
	i = 0;
	while (i + 1 < s->size)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->size - 1] = bottom;
}
