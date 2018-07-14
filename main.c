#include <stdio.h>
#include <string.h>
#include "player.h"
#include "list.h"
#include "queue.h"
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include "team.h"

// high level algorithm
// initialize all the players and teams
//   add players to teams
//   add teams to team list
// for each team
//   sort the players by their abr
//   enqueue the top 9 players
//   generate team abr
// sort team list by avg_abr
// print stats

void teardown(list **teams) {
  list *l = *teams;
  while (l) { // release team and team list memory
    team_t *t = l->item;
    list *next_team = l->next;

    destroy_team(t);
    free(l);

    l = next_team;
  }
}

void assign_to_team(player_t *player, list **teams) {
  team_t *t = find_or_create_team(teams, player->team);
  insert_player(t, player);
}

void initialize_teams(FILE *file, list **teams) {
  char player_string[10000];
  char *stats[30];
  while ((fgets(player_string, 10000, file) != NULL)) {
    char *stat;
    int i = 0;
    char *ps_ptr = player_string;
    while ((stat = strsep(&ps_ptr, ",")) != NULL) {
      stats[i] = stat;
      i++;
    }
    player_t *p = create_player(stats);
    assign_to_team(p, teams);
  }
}

void print_stats(list **teams) {
  list *l = *teams;
  while (l) {
    team_t *t = l->item;
    printf("%s\t%f\n", t->name, t->avg_abr);
    l = l->next;
  }
}

int main(int argc, const char * argv[]) {
  FILE *file = fopen(argv[1], "r");
  list *teams = NULL;
  initialize_teams(file, &teams);
  list* head = teams;
  while (head) {
    team_t *t = head->item;
    compute_best_abrs(t);
    calculate_team_abr(t);
    head = head->next;
  }
  teams = sort_list(teams, lower_abr);
  print_stats(&teams);
  teardown(&teams);
  return 0;
}
