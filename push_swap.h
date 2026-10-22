/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoronts <nvoronts@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:20:35 by nvoronts          #+#    #+#             */
/*   Updated: 2026/10/22 19:00:18 by nvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

typedef enum mode_e
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_mode;

/* The top is arr[size - 1]; arr[0] is the bottom. */
typedef struct stack_s
{
	size_t	cap;
	size_t	size;
	int		*arr;
}	t_stack;

typedef struct bench_s
{
	double		disorder;
	const char	*strategy;
	size_t		total_ops;
	size_t		sa;
	size_t		sb;
	size_t		ss;
	size_t		pa;
	size_t		pb;
	size_t		ra;
	size_t		rb;
	size_t		rr;
	size_t		rra;
	size_t		rrb;
	size_t		rrr;
}	t_bench;

typedef struct cfg_s
{
	t_mode	mode;
	t_bool	is_bench;
	t_bench	*bench;
	t_stack	stack;
	t_stack	b;
}	t_cfg;

enum	e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

const char	*op_name(int op);
t_cfg		parse_arguments(int argc, char **argv);
int			parse_tokens(char *s, t_stack *stack, t_bool fill);
int			is_space(char ch);
void		clear_cfg(t_cfg *cfg);
void		cfg_error(t_cfg *cfg);
void		exit_with_error(const char *err);
void		putstr_fd(const char *s, int fd);
void		putnum_fd(size_t n, int fd);
double		compute_disorder(t_stack stack);
void		choose_strategy(t_cfg *cfg);
void		print_bench(t_bench *bench);
void		init_bench(t_cfg *cfg);
int			prepare(t_cfg *cfg);
int			is_sorted(t_stack *s);
int			stack_at(t_stack *s, size_t index);
size_t		index_max(t_stack *s);
void		bring_top(t_cfg *cfg, size_t index, int on_b);
void		sort_small(t_cfg *cfg);
void		sort_simple(t_cfg *cfg);
void		sort_medium(t_cfg *cfg);
void		sort_complex(t_cfg *cfg);
t_stack		bubble_sort(t_cfg cfg);
void		run_sort(t_cfg *cfg);
void		operate(t_cfg *cfg, int op);
void		record_op(t_bench *bench, size_t *counter, const char *name);
void		stack_swap(t_stack *s);
void		stack_push(t_stack *dst, t_stack *src);
void		stack_rotate(t_stack *s);
void		stack_reverse(t_stack *s);
void		sa(t_stack *a, t_bench *bench);
void		sb(t_stack *b, t_bench *bench);
void		ss(t_stack *a, t_stack *b, t_bench *bench);
void		pa(t_stack *a, t_stack *b, t_bench *bench);
void		pb(t_stack *a, t_stack *b, t_bench *bench);
void		ra(t_stack *a, t_bench *bench);
void		rb(t_stack *b, t_bench *bench);
void		rr(t_stack *a, t_stack *b, t_bench *bench);
void		rra(t_stack *a, t_bench *bench);
void		rrb(t_stack *b, t_bench *bench);
void		rrr(t_stack *a, t_stack *b, t_bench *bench);

#endif
