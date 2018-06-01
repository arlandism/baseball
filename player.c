#include "player.h"
#include <stdlib.h>
#include <string.h>

int effective_plate_appearances(player_t p) {
  return p.at_bat + p.walks;
}

float strikeout_percentage(player_t p) {
  return p.strikeouts / (float) effective_plate_appearances(p);
}

void normalize_name(char *name) {
  size_t len = strlen(name);
  char last = name[len - 1];
  if (last == '#' || last == '*')
    name[len - 1] = '\0';
}

player_t create_player(char **stats) {
  player_t p;
  normalize_name(stats[0]);
  p.name = stats[0];
  p.age = atoi(stats[1]);
  p.team = stats[2];
  p.league = stats[3];
  p.g = atoi(stats[4]);
  p.plate_appearances = atoi(stats[5]);
  p.at_bat = atoi(stats[6]);
  p.runs = atoi(stats[7]);
  p.hits = atoi(stats[8]);
  p.doubles = atoi(stats[9]);
  p.triples = atoi(stats[10]);
  p.home_runs = atoi(stats[11]);
  p.runs_batted_in = atoi(stats[12]);
  p.stolen_bases = atoi(stats[13]);
  p.caught_stealing = atoi(stats[14]);
  p.walks = atoi(stats[15]);
  p.strikeouts = atoi(stats[16]);
  p.batting_avg = atof(stats[17]);
  p.onbase_percentage = atof(stats[18]);
  p.slugging_percentage = atof(stats[19]);
  p.onbase_plus_slugging = atof(stats[20]);
  p.ops_plus = atoi(stats[21]);
  p.total_bases = atoi(stats[22]);
  p.gdp = atoi(stats[23]);
  p.hit_by_pinch = atoi(stats[24]);
  p.sh = atoi(stats[25]);
  p.sacrifice_fly = atoi(stats[26]);
  p.intentional_walk = atoi(stats[27]);
  return p;
}
