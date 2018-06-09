#ifndef LIST_H
#define LIST_H
#include "player.h"
typedef struct player_list {
  player_t *player;
  struct player_list *next;
} player_list;

player_list * insert(player_list *l, player_t *p);

player_list *search(player_list *head, player_t *p);
#endif
