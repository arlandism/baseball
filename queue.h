#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
#include "player.h"
typedef struct player_queue {
  player_list *list;
} player_queue;

void enqueue(player_queue *, player_t *);
player_t * dequeue(player_queue *);
#endif

