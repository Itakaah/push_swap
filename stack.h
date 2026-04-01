#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

#endif
