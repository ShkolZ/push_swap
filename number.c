/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:56:38 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 18:23:04 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}

static int	parse_number(char **s, int *value)
{
	long long	n;
	long long	limit;
	int			sign;

	n = 0;
	sign = 1;
	if (**s == '-' || **s == '+')
		if (*(*s)++ == '-')
			sign = -1;
	limit = (long long)INT_MAX + (sign == -1);
	if (**s < '0' || **s > '9')
		return (0);
	while (**s >= '0' && **s <= '9')
	{
		if (n > (limit - (**s - '0')) / 10)
			return (0);
		n = n * 10 + *(*s)++ - '0';
	}
	*value = (int)(n * sign);
	return (**s == '\0' || is_space(**s));
}

int	parse_tokens(char *s, t_stack *stack, t_bool fill)
{
	size_t	before;
	int		value;

	before = stack->size;
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (!*s)
			break ;
		if (!parse_number(&s, &value) || stack->size == INT_MAX)
			return (0);
		if (fill)
		{
			if (stack->size >= stack->cap)
				return (0);
			stack->arr[stack->cap - stack->size - 1] = value;
		}
		stack->size++;
	}
	return (stack->size > before);
}
