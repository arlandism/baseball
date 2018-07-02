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

list * sort_list(list *head, int comparator (void *a, void *b)) {
  int size = size_of_list(head);
  if (size == 1) return head;
  list *split = split_list(head, size / 2);
  return merge_lists(
      sort_list(head, comparator),
      sort_list(split, comparator),
      comparator);
}

// split point should be guaranteed to be at least 1
list * split_list(list *head, int split_point) {
  list *prior = NULL;
  while(head && split_point > 0) {
    prior = head;
    head = head->next;
    split_point -= 1;
  }
  prior->next = NULL;
  return head;
}

int size_of_list(list *head) {
  if (head == NULL) return 0;
  int size = 1;
  while(head) {
    head = head->next;
    size += 1;
  }
  return size;
}

list * merge_lists(list *l_one, list *l_two, int comparator (void *a, void *b)) {
  list *master_list = malloc(sizeof(list));
  while(l_one && l_two) {
    if (comparator(l_one->item, l_two->item) < 0) {
      master_list->next = l_two;
      l_two = l_two->next;
    } else {
      master_list->next = l_one;
      l_one = l_one->next;
    }
  }
  // one of the lists is exhausted, so we can just append
  // the remaining one
  if (l_one) {
    master_list->next = l_one;
  } else {
    master_list->next = l_two;
  }
  return master_list;
}

void free_list(list *l) {
  free(l);
}
