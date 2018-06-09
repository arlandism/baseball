#include <stdio.h>
#include <string.h>
#include "player.h"
#include "list.h"
#include "queue.h"
#include <errno.h>
#include <stdlib.h>
#include <math.h>

typedef struct team {
  player_list *players;
  player_queue *top_nine;
  float avg_abr;
  char team[4];
} team;

typedef struct team_list {
  team *t;
} team_list;

// initialize all the players and teams
//   add players to teams
//     as we go, keep the players sorted by abr
//   add teams to team list
// for each team
//   generate team abr
//   enqueue the top 9 players
// sort team list by avg_abr
// print stats

void teardown(team_list *team) {
}

// TODO make generic list type
int initialize_teams(FILE *file, team_list *teams) {
  char player_string[10000];
  char *stats[30];
  int num_teams = 0;
  while ((fgets(player_string, 10000, file) != NULL)) {
    char *stat;
    int i = 0;
    char *ps_ptr = player_string;
    while ((stat = strsep(&ps_ptr, ",")) != NULL) {
      stats[i] = stat;
      i++;
    }
    player_t *p = create_player(stats);
    team = search(teams, p->team); // TODO search team by name
    if (team == NULL) {
      teams = realloc(teams, sizeof(team));
      if (teams == NULL) {
        exit(errno);
      }
      num_teams += 1;
      create_team(p->team); // TODO need to alloc here
    }
    insert_player(team, p); // TODO
  }
  return num_teams;
}

void print_stats(team_list *teams) {
  team *t = teams;
  while (t != NULL) {
    printf("Team: %s\nAvg ABR: %f\n", t->name, t->avg_abr);
    t = t->next;
  }
}

int main(int argc, const char * argv[]) {
  FILE *file = fopen(argv[1], "r");
  team_list *teams = NULL;
  int num_teams = initialize_teams(file, teams);
  team *t = teams;
  while (t != NULL) {
    calculate_team_abr(t); // TODO
    sort_players_by_abr(t); // TODO
    t = t->next;
  }
  sort_teams_by_abr_asc(teams); // TODO
  print_stats(teams);
  teardown(teams);
  return 0;
}
