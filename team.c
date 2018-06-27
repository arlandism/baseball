#include "player.h"
#include "team.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

team * find_or_create_team(list **teams, char *team_name) {
  team *t = find_team_by_name(teams, team_name);
  if (t == NULL) {
    t = create_team(team_name);
    insert(teams, t);
  }
  return t;
}

team * find_team_by_name(list **teams, char *team_name) {
  if (*teams == NULL) {
    return NULL;
  }

  list *l = *teams;
  team *t;
  while(l != NULL) {
    t = l->item;
    if (strcmp(t->name, team_name) == 0) {
      return t;
    }
    l = l->next;
  }
  return NULL;
}

team * create_team(char *team_name) {
  team *team = malloc(sizeof(team));
  strncpy(team->name, team_name, 3);
  printf("Team name is %s\n", team->name);
  return team;
}

void insert_player(team *t, player_t *p) {
  insert(&t->players, p);
}

void sort_players_by_abr(team *t) {
}

void calculate_team_abr(team *t) {
  list *l = t->players->item;
  float avg = 0.0;
  while(l != NULL) {
    player_t *p = l->item;
    avg += avg_base_rating(p);
    l = l->next;
  }
  avg = avg / 9;
  t->avg_abr = avg;
}
