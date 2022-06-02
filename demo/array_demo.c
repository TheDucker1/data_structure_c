#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"array.h"

#define arr_get(type, a, index) (((type *)(a->arr))[index])
void print_arr_f(array_t arr) {
    int i;
    for (i = 0; i < (int)array_size(arr); i++) {
        fprintf(stdout, "%f ", arr_get(float, arr, i));
    }
    fprintf(stdout, "\n");
}
#undef arr_get

int sort_func(const void * a, const void *b) {
    return (*(float*)(a) > *(float*)(b));
}

int main(void) {
    float f;
    array_t arr = array_new(sizeof(float));
    f = 1.0f;
    array_add(arr, &f);
    f = 3.2f;
    array_add(arr, &f);
    f = 1.45f;
    array_add(arr, &f);
    f = 9.21f;
    array_add(arr, &f);
    f = 2.0f;
    array_insert(arr, 0, &f);
    f = 9.0f;
    array_insert(arr, 0, &f);
    f = 2.2f;
    array_insert(arr, 0, &f);
    
    array_get(arr, 1, &f);
    fprintf(stdout, "2nd elem: %f \n", f);
    array_get2(arr, -1, &f);
    fprintf(stdout, "Last elem: %f \n", f);
    print_arr_f(arr);
    f = 9.99f;
    array_assign(arr, 0, &f);
    print_arr_f(arr);
    array_sort(arr, sort_func);
    print_arr_f(arr);
    array_free(arr);
    
    return 0;
}