#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list *insert(list **head, void *item) {
  list *new_list = malloc(sizeof(list));
  new_list->item = item;
  if (*head == NULL) {
    new_list->next = NULL;
  } else {
    new_list->next = *head;
  }
  *head = new_list;
  return new_list;
}

list *search_list(list *head, void *item) {
  if (head == NULL) return NULL;
  list *l = head;
  while(l != NULL && l->item != item)
    l = l->next;
  return l;
}

void free_list(list *l) {
  free(l);
}
