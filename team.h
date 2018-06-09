#ifndef TEAM_H
#define TEAM_H
#include "list.h"
#include "queue.h"
#include "player.h"
typedef struct team {
  list *players;
  queue *top_nine;
  float avg_abr;
  char name[4];
} team;

team * create_team(char *team_name);

void insert_player(team *t, player_t *p);
#endif
