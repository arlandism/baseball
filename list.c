#include "list.h"
#include <stdlib.h>

list *insert(list *head, void *item) {
  list *new_list = malloc(sizeof(list));
  new_list->item = item;
  new_list->next = head;
  return new_list;
}

list *search(list *head, void *item) {
  while(head != NULL && head->item != item)
    head = head->next;
  return head;
}

void free_list(list *l) {
  free(l);
}
