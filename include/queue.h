#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _queue_t {
    size_t elem_size;
    size_t arr_max_size;
    size_t tail;
    size_t head;
    void* arr;
} _queue_t;

typedef _queue_t* queue_t;

queue_t queue_new(size_t elem_size);
#define queue_size(q) ((q->tail - q->head))
#define queue_esize(q) (q->elem_size)
size_t queue_push(queue_t queue, void * elem);
void queue_pop(queue_t queue, void * dst);
void queue_peek(queue_t queue, void * dst);
void queue_free(queue_t queue);

#endif
/* _QUEUE_H_ */