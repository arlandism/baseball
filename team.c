#include "player.h"
#include "team.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

team_t * find_or_create_team(list **teams, char *team_name) {
  team_t *t = find_team_by_name(teams, team_name);
  if (t == NULL) {
    t = create_team(team_name);
    insert(teams, t);
  }
  return t;
}

team_t * find_team_by_name(list **teams, char *team_name) {
  list *l = *teams;
  team_t *t;
  while(l != NULL) {
    t = l->item;
    if (strcmp(t->name, team_name) == 0) {
      return t;
    }
    l = l->next;
  }
  return NULL;
}

team_t * create_team(char *team_name) {
  team_t *team = malloc(sizeof(team_t));
  strlcpy(team->name, team_name, 4);
  team->players = NULL;
  team->top_nine = initialize_queue();
  return team;
}

void destroy_team(team_t *t) {
  list *players = t->players;
  while (players) { // release player and player list memory
    player_t *p = players->item;
    list *next = players->next;
    free(p);
    free(players);
    players = next;
  }
  free(t);
}

void insert_player(team_t *t, player_t *p) {
  insert(&t->players, p);
}

int lower_abr(void *x, void *y) {
  team_t *t_one = x;
  team_t *t_two = y;

  if (t_one->avg_abr < t_two->avg_abr) {
    return 1;
  } else if (t_one->avg_abr == t_two->avg_abr) {
    // alphabetical comparison on match
    // invert the meaning with '-' since strcmp returns greater than, equal to, or less than 0
    // according to whether the first string comes after, is equal to, or comes before
    // the second (i.e. the exact opposite of what we want)
    return -strcmp(t_one->name, t_two->name);
  }
  return -1;
}

void compute_best_abrs(team_t *t) {
  t->players = sort_list(t->players, higher_abr);
  list *players = t->players;
  for(int i = 0; i < 10; i++) {
    player_t *player = players->item;
    enqueue(t->top_nine, player);
    players = players->next;
  }
}

void calculate_team_abr(team_t *t) {
  float avg = 0.0;
  player_t *p;
  while((p = dequeue(t->top_nine)) != NULL) {
    avg += avg_base_rating(p);
  }
  avg = avg / 9;
  t->avg_abr = avg;
}
