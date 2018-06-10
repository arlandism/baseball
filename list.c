#include "list.h"
#include <stdlib.h>

list *insert(list *head, void *item) {
  list *new_list = malloc(sizeof(list));
  new_list->item = item;
  new_list->next = head;
  return new_list;
}

list *search_list(list **head, void *item) {
  list *l = *head;
  while(l != NULL && l->item != item)
    l = l->next;
  return l;
}

void free_list(list *l) {
  free(l);
}
