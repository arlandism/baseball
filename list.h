#ifndef LIST_H
#define LIST_H
/* Generic Linked List Implementation */

typedef struct list {
  void *item;
  struct list *next;
} list;

list * insert(list **head, void *item);

list *search_list(list *l, void *item);
void sort_list(list *head, int comparator (void *a, void *b));
void free_list(list *l);
#endif
