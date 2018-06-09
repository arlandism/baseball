#include "list.h"
#include "player.h"
#include <stdlib.h>

player_list *insert(player_list *head, player_t *p) {
  player_list *new_list = malloc(sizeof(player_list));
  new_list->player = p;
  new_list->next = head;
  return new_list;
}

player_list *search(player_list *head, player_t *p) {
  while(head != NULL && head->player != p)
    head = head->next;
  return head;
}

void delete(player_list *head, player_t *p) {
}
