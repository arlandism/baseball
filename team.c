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
