#include <stdio.h>
#include <string.h>
#include "player.h"
#include "list.h"
#include "queue.h"
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include "team.h"

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
int initialize_teams(FILE *file, list **teams) {
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
    if (team_node == NULL) {
      teams = realloc(teams, sizeof(team));
      if (teams == NULL) {
        exit(errno);
      }
      num_teams += 1;
      team *team = create_team(p->team); // TODO need to alloc here
    }
    insert_player(team, p);
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

typedef struct linked_list {
  struct linked_list *next;
  void *item;
} linked_list;

void insert_string(linked_list ***names, char *item) {
  linked_list *l = malloc(sizeof(linked_list));
  l->item = item;
  (*names) = &l;
}

void insert_int(linked_list ***names, int *item) {
  linked_list *l = malloc(sizeof(linked_list));
  l->item = item;
  (*names) = &l;
}

int main(int argc, const char * argv[]) {
  linked_list **names = NULL;
  insert_string(&names, "Arlandis");
  int num = 3;
  insert_int(&names, &num);
  printf("The first name is %s\n", (*names)->item);
  printf("The first int is %d\n", (*(*names)->next->item));
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
