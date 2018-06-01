#include <stdio.h>
#include <string.h>
#include "player.h"
#include <errno.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
  printf("%20s\t%3s\t%3s%%\n", "Player Name", "EPA", "K");
  FILE *file = fopen(argv[1], "r");
  char player_string[10000];
  char *stats[30];
  player_t ** players = NULL;
  int j = 0;
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
    players[j] = p;
    printf("%20s\t%3d\t%.1f%%\n", p->name, effective_plate_appearances(p), strikeout_percentage(p) * 100);
    destroy_player(p);
  }
  for (int k = 0; k < j; k++) {
    free(players[k]);
  }
  return 0;
}
