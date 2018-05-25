#include <stdio.h>
#include <string.h>
#include "player.h"

int effective_plate_appearances(struct player p) {
  return 2;
}

float strikeout_percentage(struct player p) {
  return p.strikeouts / (float) effective_plate_appearances(p);
}

struct player create_player(char *stats) {
  struct player p;
  *p.name = stats[0];
  return p;
}

int main(int argc, const char * argv[]) {
  printf("Player Name\tEPA\tK%%\n");
  FILE *file = fopen(argv[1], "r");
  char player_string[10000];
  char *ps_ptr = player_string;
  char **stats[1000][1000];
  while (fgets(player_string, 10000, file) != NULL) {
    char *stat;
    struct player p;
    int i = 0;
    while ((stat = strsep(&ps_ptr, ",")) != NULL) {
      *stats[i] = stat;
      i++;
    }
    p = create_player(*stats);
    printf("%s\t%d\t%.1f\n", p.name, effective_plate_appearances(p), strikeout_percentage(p));
  }
  return 0;
}
