
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct cfg_s
{
    Mode mode;
    Bool is_bench;
} cfg_t;

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

cfg_t parse_arguments(int argc, char **argv);

#endif