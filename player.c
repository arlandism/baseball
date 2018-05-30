#include "player.h"
#include <stdlib.h>

int effective_plate_appearances(struct player p) {
  return p.at_bat + p.base_on_balls;
}

float strikeout_percentage(struct player p) {
  return p.strikeouts / (float) effective_plate_appearances(p);
}

struct player create_player(char **stats) {
  struct player p;
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
  p.base_on_balls = atoi(stats[17]);
  p.ba = (float) *stats[18];
  p.onbase_percentage = (float) *stats[19];
  p.slugging_percentage = (float) *stats[20];
  p.onbase_plus_slugging = (float) *stats[21];
  p.ops_plus = atoi(stats[22]);
  p.total_bases = atoi(stats[23]);
  p.gdp = atoi(stats[24]);
  p.hit_by_pinch = atoi(stats[25]);
  p.sh = atoi(stats[26]);
  p.sacrifice_fly = atoi(stats[27]);
  p.intentional_walk = atoi(stats[28]);
  return p;
}
