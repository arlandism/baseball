#include <stdio.h>
#include <string.h>
#include "player.h"

int effective_plate_appearances(struct player p) {
  return 2;
}

float strikeout_percentage(struct player p) {
  return p.strikeouts / (float) effective_plate_appearances(p);
}

int main(int argc, const char * argv[]) {
  printf("Player Name\tEPA\tK%%\n");
  FILE *file = fopen(argv[1], "r");
  char player_string[1000];
  char *ps_ptr = player_string;
  while (fgets(player_string, 1000, file) != NULL) {
    char *stat;
    struct player p;
    while ((stat = strsep(&ps_ptr, ",")) != NULL) {
      printf("Stat is %s\n", stat);
    }
    printf("%s\t%d\t%.1f\n", p.name, effective_plate_appearances(p), strikeout_percentage(p));
  }
  return 0;
}
