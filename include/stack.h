#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _stack_t {
    size_t elem_size;
    size_t arr_max_size;
    size_t arr_cur_size;
    void* arr;
} _stack_t;

typedef _stack_t* stack_t;

stack_t stack_new(size_t elem_size);
#define stack_size(s) (s->arr_cur_size)
#define stack_esize(s) (s->elem_size)
size_t stack_push(stack_t stack, void * elem);
void stack_pop(stack_t stack, void* dst);
void stack_peek(stack_t stack, void* dst);
void stack_free(stack_t stack);

#endif 
/* _STACK_H_ */