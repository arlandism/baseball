#include "queue.h"
#include "player.h"
#include "list.h"
#include <stdlib.h>

queue* initialize_queue() {
  queue* q = malloc(sizeof(queue));
  q->list = NULL;
  return q;
}

void enqueue(queue *q, void *item) {
  insert(&q->list, item);
}

void * dequeue(queue *q) {
  list *tail = q->list;
  list *prior = NULL;

  // empty case
  if (tail == NULL) return NULL;

  // advance to the end of the list
  while (tail->next != NULL) {
    prior = tail;
    tail = tail->next;
  }

  // last node
  if (prior == NULL && tail->next == NULL) {
    q->list = NULL;
  } else {
    // remove node from list
    (*prior).next = NULL;
  }

  void *item = tail->item;
  free(tail);

  return item;
}
