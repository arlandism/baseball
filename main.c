#include <stdio.h>
#include <string.h>
#include "player.h"
#include "list.h"
#include "queue.h"
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include "team.h"

// initialize all the players and teams
//   add players to teams
//     as we go, keep the players sorted by abr
//   add teams to team list
// for each team
//   generate team abr
//   enqueue the top 9 players
// sort team list by avg_abr
// print stats

void teardown(list **teams) {
}

void initialize_teams(FILE *file, list **teams) {
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
    list *team_node = search_list(teams, p->team);
    team *team;
    if (team_node == NULL) {
      teams = realloc(teams, sizeof(team));
      if (teams == NULL) {
        exit(errno);
      }
      num_teams += 1;
      team = create_team(p->team); // TODO need to alloc here
    } else {
      team = team_node->item;
    }

    insert_player(team, p);
  }
}

void print_stats(list **teams) {
  list *l = (*teams);
  while (l != NULL) {
    team *team = l->item;
    printf("Team: %s\nAvg ABR: %f\n", team->name, team->avg_abr);
    l = l->next;
  }
}

void sort_teams_by_abr_asc(team **teams) {
}

int main(int argc, const char * argv[]) {
  list **names = NULL;
  printf("The first name is %s\n", (*names)->item);
  FILE *file = fopen(argv[1], "r");
  list **teams = NULL;
  initialize_teams(file, teams);
  list *l = *teams;
  while (l != NULL) {
    calculate_team_abr(l->item);
    sort_players_by_abr(l->item);
    l = l->next;
  }
  sort_teams_by_abr_asc(teams);
  print_stats(teams);
  teardown(teams);
  return 0;
}
