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
} team_t;

team_t * find_or_create_team(list **teams, char *team_name);
team_t * find_team_by_name(list **teams, char *team_name);
team_t * create_team(char *team_name);
void insert_player(team_t *t, player_t *p);
void calculate_team_abr(team_t *t);
void sort_players_by_abr(team_t *t);
int lower_abr(void *x, void *y);

#endif
