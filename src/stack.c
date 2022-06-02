#include"stack.h"

stack_t stack_new(size_t elem_size) {
    stack_t stack = (stack_t)malloc(sizeof(_stack_t));
    stack->elem_size = elem_size;
    stack->arr_max_size = 1;
    stack->arr_cur_size = 0;
    stack->arr = (void*)malloc(elem_size);
    return stack;
}

size_t stack_push(stack_t s, void * elem) {
    if (s->arr_cur_size >= s->arr_max_size) { 
        /* '>' should not happen */
        size_t t = s->arr_max_size << 1;
        if (t <= 0) { 
            /* overflow, signed(?!) */
            fprintf(stderr, "max stack size reached, cannot add more data\n");
            return s->arr_cur_size;
        }
        s->arr_max_size = t;
        void * tmp = realloc(s->arr, s->elem_size * s->arr_max_size);
        if (tmp == NULL) {
            fprintf(stderr, "memory error, cannot push element\n");
            return s->arr_cur_size;
        }
        s->arr = tmp;
    }
    memcpy(s->arr + (s->arr_cur_size++) * s->elem_size, elem, s->elem_size);
    
    return s->arr_cur_size;
}

void stack_pop(stack_t s, void * dst) {
    if (s->arr_cur_size == 0) {
        fprintf(stderr, "empty stack, cannot pop\n");
        return;
    }
    memcpy(dst, s->arr + (--s->arr_cur_size) * s->elem_size, s->elem_size);
    
    while ((s->arr_max_size > 1) && ((s->arr_max_size >> 1)) >= s->arr_cur_size) {
        size_t t_size = s->arr_max_size >> 1;
        void * t = realloc(s->arr, s->elem_size * t_size);
        if (t == NULL) {
            /* this should not happen */
            fprintf(stderr, "cannot change stack size\n");
            return;
        }
        s->arr = t;
        s->arr_max_size = t_size;
    }
    return;
}

void stack_peek(stack_t s, void * dst) {
    if (s->arr_cur_size == 0) {
        fprintf(stderr, "empty stack, cannot peek\n");
        return;
    }
    memcpy(dst, s->arr + (s->arr_cur_size-1) * s->elem_size, s->elem_size);
    return;
}

void stack_free(stack_t s) {
    free(s->arr);
    free(s);
    return;
}