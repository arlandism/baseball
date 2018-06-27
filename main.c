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

void assign_to_team(player_t *player, list **teams) {
  // this may change the HEAD of the list
  team_t *t = find_or_create_team(teams, player->team);
  insert_player(t, player);
}

void initialize_teams(FILE *file, list **teams) {
  char player_string[10000];
  char *stats[30];
  int num_teams = 1;
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
}

void sort_teams_by_abr_asc(list **teams) {
}

int main(int argc, const char * argv[]) {
  FILE *file = fopen(argv[1], "r");
  list *teams = NULL;
  initialize_teams(file, &teams);
  list* head = teams;
//  while (head) {
//    team_t *t = head->item;
//    printf("Team name is %s\n", t->name);
//    head = head->next;
//  }
//  printf("Teams is pointing at %p\n", teams);
//  list *l = *teams;
//  while (l != NULL) {
//    calculate_team_abr(l->item);
//    sort_players_by_abr(l->item);
//    l = l->next;
//  }
////  sort_teams_by_abr_asc(teams);
//  print_stats(teams);
//  teardown(teams);
  return 0;
}
