#ifndef _ARRAY_H_
#define _ARRAY_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _array_t {
    size_t elem_size;
    size_t arr_max_size;
    size_t arr_cur_size;
    void* arr;
} _array_t;

typedef _array_t* array_t;

array_t array_new(size_t elem_size);
#define array_size(a) ((a->arr_cur_size))
#define array_esize(a) ((a->elem_size))
size_t array_add(array_t arr, void * elem);
size_t array_insert(array_t arr, size_t index, void * elem);

void array_assign(array_t arr, size_t index, void * elem);
void array_get(array_t arr, size_t index, void * dst);
void array_get2(array_t arr, int index, void * dst);
void array_sort(array_t arr, int (*cmp_func)(const void * a, const void * b));
void array_free(array_t arr);

#endif 
/* _ARRAY_H_ */