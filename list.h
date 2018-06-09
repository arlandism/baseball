#ifndef LIST_H
#define LIST_H
/* Generic Linked List Implementation */

typedef struct list {
  void *item;
  struct list *next;
} list;

list * insert(list *l, void *item);

list *search(list *head, void *item);
#endif
