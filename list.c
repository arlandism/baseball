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

int size_of_list(list *head) {
  int size = 0;
  while(head) {
    head = head->next;
    size += 1;
  }
  return size;
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

list * merge_lists(list *l_one, list *l_two, int comparator (void *a, void *b)) {
  list *head = NULL, *iterator = NULL;
  if (comparator(l_one->item, l_two->item) < 0) {
    head = l_two;
    iterator = l_two;
    l_two = l_two->next;
  } else {
    head = l_one;
    iterator = l_one;
    l_one = l_one->next;
  }

  while(l_one && l_two) {
    if (comparator(l_one->item, l_two->item) < 0) {
      iterator->next = l_two;
      l_two = l_two->next;
    } else {
      iterator->next = l_one;
      l_one = l_one->next;
    }
    iterator = iterator->next;
  }
  // one of the lists is exhausted, so we can just append
  // the remaining one
  if (l_one) {
    iterator->next = l_one;
  } else {
    iterator->next = l_two;
  }
  return head;
}

void free_list(list *l) {
  free(l);
}
