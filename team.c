#include "player.h"
#include "team.h"
#include <string.h>
#include <stdlib.h>

team * create_team(char *team_name) {
  team *team = malloc(sizeof(team));
  strncpy(team->name, team_name, 3);
  return team;
}

void insert_player(team *t, player_t *p) {
  insert(t->players, p);
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
