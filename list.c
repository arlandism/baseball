#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list *insert(list **head, void *item) {
  list *new_list = malloc(sizeof(list));
  new_list->item = item;
  new_list->next = *head;
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

void sort_list(list *head, int comparator (void *a, void *b)) {
  list *node = head;
  while(node) {
    list *other_base = head;
    while(comparator(other_base->item, node->item) < 0) {
      void *tmp = node->item;
      node->item = other_base->item;
      other_base->item = tmp;
      other_base = other_base->next;
    }
    node = node->next;
  }
}

void free_list(list *l) {
  free(l);
}
