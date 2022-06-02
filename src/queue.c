#include"queue.h"

queue_t queue_new(size_t elem_size) {
    queue_t q = (queue_t)malloc(sizeof(_queue_t));
    q->elem_size = elem_size;
    q->arr_max_size = 1;
    q->tail = 0;
    q->head = 0;
    q->arr = (void*)malloc(elem_size);
    return q;
}

size_t queue_push(queue_t q, void * elem) {
    if (queue_size(q) >= q->arr_max_size) { 
        /* '>' should not happen */
        size_t t = q->arr_max_size << 1;
        if (t <= 0) { 
            /* overflow, signed(?!) */
            fprintf(stderr, "max queue size reached, cannot add more data\n");
            return queue_size(q);
        }
        q->arr_max_size = t;
        void * tmp = realloc(q->arr, q->elem_size * q->arr_max_size);
        if (tmp == NULL) {
            fprintf(stderr, "memory error, cannot push element\n");
            return queue_size(q);
        }
        q->arr = tmp;
    }
    memcpy(q->arr + (q->tail++) * q->elem_size, elem, q->elem_size);
    
    return queue_size(q);
}

void queue_pop(queue_t q, void * dst) {
    if (queue_size(q) == 0) {
        fprintf(stderr, "empty queue, cannot pop\n");
        return;
    }
    memcpy(dst, q->arr + (q->head++) * q->elem_size, q->elem_size);
    
    while ((q->arr_max_size > 1) && ((q->arr_max_size >> 1)) >= queue_size(q)) {
        size_t t_size = q->arr_max_size >> 1;
        if (!q->head) {
            memmove(q->arr, q->arr + q->head * q->elem_size, queue_size(q) * q->elem_size);
            q->tail -= q->head;
            q->head = 0;
        }
        
        void * t = realloc(q->arr, q->elem_size * t_size);
        if (t == NULL) {
            /* this should not happen */
            fprintf(stderr, "cannot change stack size\n");
            return;
        }
        q->arr = t;
        q->arr_max_size = t_size;
    }
    return;
}

void queue_peek(queue_t q, void * dst) {
    if (queue_size(q) == 0) {
        fprintf(stderr, "empty queue, cannot pop\n");
        return;
    }
    memcpy(dst, q->arr + (q->head) * q->elem_size, q->elem_size);
    return;
}
void queue_free(queue_t q) {
    free(q->arr);
    free(q);
}