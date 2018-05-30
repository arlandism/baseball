#include <stdio.h>
#include <string.h>
#include "player.h"

int main(int argc, const char * argv[]) {
  printf("%20s\t%3s\t%3s%%\n", "Player Name", "EPA", "K");
  FILE *file = fopen(argv[1], "r");
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
    struct player p = create_player(stats);
    printf("%20s\t%3d\t%.1f\n", p.name, effective_plate_appearances(p), strikeout_percentage(p));
  }
  return 0;
}
