#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main(void) {
    float f[] = {3.14f, 2.89f, 33.21f, 921.f, 0.22f, 21.222222f};
    size_t sz = 6;
    size_t i;
    queue_t q = queue_new(sizeof(float));
    for (i = 0; i < sz; i++) {
        queue_push(q, &f[i]);
    }
    float t;
    for (i = 0; i < sz >> 1; i++) {
        queue_peek(q, &t);
        fprintf(stdout, "%f ", t);
    }
    for (i = 0; i < sz; i++) {
        queue_pop(q, &t);
        fprintf(stdout, "%f ", t);
    }
    fprintf(stdout, "\n");
    queue_free(q);
    
    return 0;
}