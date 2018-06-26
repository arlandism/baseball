#include "player.h"
#include "team.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

team * find_or_create_team(list **teams, char *team_name) {
  list *l = search_list(teams, team_name);
  if (l == NULL) {
    team *t = create_team(team_name);
    l = insert(teams, t);
  }
  if (teams == NULL) {
    teams = &l;
  }
  return l->item;
}

team * create_team(char *team_name) {
  team *team = malloc(sizeof(team));
  strncpy(team->name, team_name, 3);
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
