#include "queue.h"
#include "player.h"
#include "list.h"
#include <stdlib.h>

void enqueue(player_queue *q, player_t *p) {
  insert(q->list, p);
}

player_t * dequeue(player_queue *q) {
  player_list *tail = q->list;
  while (tail->next != NULL)
    tail = tail->next;
  if (tail) return tail->player;
  return NULL;
}
