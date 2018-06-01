#include <stdio.h>
#include <string.h>
#include "player.h"
#include <errno.h>
#include <stdlib.h>

void teardown(player_t **players, int player_count) {
  for (int i = 0; i < player_count; i++) {
    destroy_player(players[i]);
    free(&players[i]);
  }
}

int create_players(FILE *file, player_t **players) {
  char player_string[10000];
  char *stats[30];
  int num_players = 0;
  while ((fgets(player_string, 10000, file) != NULL)) {
    char *stat;
    int i = 0;
    char *ps_ptr = player_string;
    while ((stat = strsep(&ps_ptr, ",")) != NULL) {
      stats[i] = stat;
      i++;
    }
    players = realloc(players, sizeof(players) + sizeof(player_t *));
    if (players == NULL) {
      exit(errno);
    }
    player_t *p = create_player(stats);
    players[num_players] = p;
  }
  return num_players;
}

int main(int argc, const char * argv[]) {
  printf("%20s\t%3s\t%3s%%\n", "Player Name", "EPA", "K");
  FILE *file = fopen(argv[1], "r");
  player_t ** players = NULL;
  int num_players = create_players(file, players);
  teardown(players, num_players);
  return 0;
}
