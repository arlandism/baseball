#include "player.h"
#include "team.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

team_t * find_or_create_team(list **teams, char *team_name) {
  team_t *t = find_team_by_name(teams, team_name);
  if (t == NULL) {
    t = create_team(team_name);
    insert(teams, t);
    t = (*teams)->item;
  }
  return t;
}

team_t * find_team_by_name(list **teams, char *team_name) {
  if (*teams == NULL) {
    return NULL;
  }

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
  return team;
}

void insert_player(team_t *t, player_t *p) {
  insert(&t->players, p);
}

void sort_players_by_abr(team_t *t) {
}

void calculate_team_abr(team_t *t) {
  float avg = 0.0;
  list *l = t->players;
  while(l != NULL) {
    player_t *p = l->item;
    avg += avg_base_rating(p);
    l = l->next;
  }
  avg = avg / 9;
  t->avg_abr = avg;
}
