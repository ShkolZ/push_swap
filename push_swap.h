
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct bench_s
{
    float disorder;
    char *strategy;
    size_t total_ops;
    size_t sa;
    size_t sb;
    size_t ss;
    size_t pa;
    size_t pb;
    size_t ra;
    size_t rb;
    size_t rr;
    size_t rra;
    size_t rrb;
    size_t rrr;
} bench_t;
typedef struct cfg_s
{
    Mode mode;
    Bool is_bench;
    bench_t *bench;
    stack_t stack;
} cfg_t;

typedef struct stack_s
{
    size_t cap;
    size_t size;
    int *arr;
} stack_t;

typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef enum mode_e
{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
} Mode;

/*              HELPERS                */
cfg_t parse_arguments(int argc, char **argv);
// Exits with error message
void exit_with_error(const char *err);
// Computes disorder
float compute_disorder(stack_t stack);

/*              OPERATIONS             */
// Swap a
void sa(stack_t *a, bench_t *bench);
// Swap b
void sb(stack_t *b, bench_t *bench);
// Swap a and b
void ss(stack_t *a, stack_t *b, bench_t *bench);
// Push from b to a
void pa(stack_t *a, stack_t *b, bench_t *bench);
// Push from a to b
void pb(stack_t *a, stack_t *b, bench_t *bench);
// Rotate a
void ra(stack_t *a, bench_t *bench);
// Rotate b
void rb(stack_t *b, bench_t *bench);
// Rotate both
void rr(stack_t *a, stack_t *b, bench_t *bench);
// Reverse rotate a
void rra(stack_t *a, bench_t *bench);
// Reverse rotate b
void rrb(stack_t *b, bench_t *bench);
// Reverse rotate both
void rrr(stack_t *a, stack_t *b, bench_t *bench);

/*              ALGORITHMS              */
stack_t bubble_sort(cfg_t cfg);

#endif