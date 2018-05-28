#include <stdio.h>
#include <string.h>
#include "player.h"

int effective_plate_appearances(struct player p) {
  return p.at_bat + p.base_on_balls;
}

float strikeout_percentage(struct player p) {
  return p.strikeouts / (float) effective_plate_appearances(p);
}

struct player create_player(char **stats) {
  struct player p;
  p.name = stats[0];
  p.age = (int) *stats[1];
  p.team = stats[2];
  p.league = stats[3];
  p.g = (int) *stats[4];
  p.plate_appearances = (int) *stats[5];
  p.at_bat = (int) *stats[6];
  p.runs = (int) *stats[7];
  p.hits = (int) *stats[8];
  p.doubles = (int) *stats[9];
  p.triples = (int) *stats[10];
  p.home_runs = (int) *stats[11];
  p.runs_batted_in = (int) *stats[12];
  p.stolen_bases = (int) *stats[13];
  p.caught_stealing = (int) *stats[14];
  p.walks = (int) *stats[15];
  p.strikeouts = (int) *stats[16];
  p.base_on_balls = (int) *stats[17];
  p.ba = (float) *stats[18];
  p.onbase_percentage = (float) *stats[19];
  p.slugging_percentage = (float) *stats[20];
  p.onbase_plus_slugging = (float) *stats[21];
  p.ops_plus = (int) *stats[22];
  p.total_bases = (int) *stats[23];
  p.gdp = (int) *stats[24];
  p.hit_by_pinch = (int) *stats[25];
  p.sh = (int) *stats[26];
  p.sacrifice_fly = (int) *stats[27];
  p.intentional_walk = (int) *stats[28];
  return p;
}

int main(int argc, const char * argv[]) {
  printf("%20s\t%3s\t%3s%%\n", "Player Name", "EPA", "K");
  FILE *file = fopen(argv[1], "r");
  char player_string[10000];
  char *stats[30];
  while ((fgets(player_string, 10000, file) != NULL)) {
    char *stat;
    struct player p;
    int i = 0;
    char *ps_ptr = player_string;
    while ((stat = strsep(&ps_ptr, ",")) != NULL) {
      stats[i] = stat;
      i++;
    }
    p = create_player(stats);
    printf("%20s\t%3d\t%.1f\n", p.name, effective_plate_appearances(p), strikeout_percentage(p));
  }
  return 0;
}
