#ifndef LIST_H
#define LIST_H
/* Generic Linked List Implementation */

typedef struct list {
  void *item;
  struct list *next;
} list;

list * insert(list **head, void *item);

list *search_list(list *l, void *item);
list *sort_list(list *head, int comparator (void *a, void *b));
list * split_list(list *head, int split_point);
list *merge_lists(list *l_one, list *l_two, int comparator(void *a, void *b));
int size_of_list(list *l);
void free_list(list *l);
#endif
