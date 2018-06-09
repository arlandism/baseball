#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
#include "player.h"
typedef struct queue {
  list *list;
} queue;

void enqueue(queue *q, void*item);
void * dequeue(queue *q);
#endif

