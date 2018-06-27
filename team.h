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

team * find_or_create_team(list **teams, char *team_name);
team * find_team_by_name(list **teams, char *team_name);
team * create_team(char *team_name);
void insert_player(team *t, player_t *p);
void calculate_team_abr(team *t);
void sort_players_by_abr(team *t);

#endif
