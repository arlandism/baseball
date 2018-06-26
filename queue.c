#include "queue.h"
#include "player.h"
#include "list.h"
#include <stdlib.h>

void enqueue(queue *q, void *item) {
  insert(&q->list, item);
}

void * dequeue(queue *q) {
  list *tail = q->list;
  while (tail->next != NULL)
    tail = tail->next;
  if (tail) return tail->item;
  return NULL;
}
