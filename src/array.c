#include"array.h"

array_t array_new(size_t elem_size) {
    array_t arr = (array_t)malloc(sizeof(_array_t));
    arr->elem_size = elem_size;
    arr->arr_max_size = 1;
    arr->arr_cur_size = 0;
    arr->arr = (void*)malloc(elem_size);
    return arr;
}

size_t array_insert(array_t a, size_t index, void * elem) {
    if (index > a->arr_cur_size) {
        fprintf(stderr, "out of bound, cannot insert element\n");
        return a->arr_cur_size;
    }
    if (a->arr_cur_size >= a->arr_max_size) { 
        /* '>' should not happen */
        size_t t = a->arr_max_size << 1;
        if (t <= 0) { 
            /* overflow, signed(?!) */
            fprintf(stderr, "max array size reached, cannot add more data\n");
            return a->arr_cur_size;
        }
        a->arr_max_size = t;
        void * tmp = realloc(a->arr, a->elem_size * a->arr_max_size);
        if (tmp == NULL) {
            fprintf(stderr, "memory error, cannot add element\n");
            return a->arr_cur_size;
        }
        a->arr = tmp;
    }
    memmove(a->arr + (index + 1) * a->elem_size, a->arr + index * a->elem_size, (a->arr_cur_size++ - index) * a->elem_size);
    memcpy(a->arr + index * a->elem_size, elem, a->elem_size);
    return a->arr_cur_size;
}

size_t array_add(array_t a, void * elem) {
    return array_insert(a, a->arr_cur_size, elem);
}

void array_assign(array_t a, size_t index, void * elem) {
    if (index >= a->arr_cur_size) {
        fprintf(stderr, "out of bound, cannot get element\n");
    }
    memcpy(a->arr + index * a->elem_size, elem, a->elem_size);
}

void array_get(array_t a, size_t index, void * dst) {
    if (index >= a->arr_cur_size) {
        fprintf(stderr, "out of bound, cannot get element\n");
    }
    memcpy(dst, a->arr + index * a->elem_size, a->elem_size);
}

void array_get2(array_t a, int index, void * dst) {
    if ((size_t)abs(index) >= a->arr_cur_size) {
        fprintf(stderr, "out of bound, cannot get element\n");
    }
    if (index < 0) {
        index += a->arr_cur_size;
    }
    array_get(a, (size_t)index, dst);
}

void array_sort(array_t a, int (*cmp_func)(const void * a, const void * b)) {
    qsort(a->arr, a->arr_cur_size, a->elem_size, cmp_func);
}

void array_free(array_t a) {
    free(a->arr);
    free(a);
}