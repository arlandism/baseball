#include "player.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int effective_plate_appearances(player_t *p) {
  return p->at_bat + p->walks;
}

float strikeout_percentage(player_t *p) {
  return p->strikeouts / (float) effective_plate_appearances(p);
}

float hitout_percentage(player_t *p) {
  return (p->at_bat - (p->hits + p->strikeouts)) / (float) effective_plate_appearances(p);
}

float walk_percentage(player_t *p) {
  return p->walks / (float) effective_plate_appearances(p);
}

float out_percentage(player_t *p) {
  return strikeout_percentage(p) + hitout_percentage(p);
}

float single_percentage(player_t *p) {
  return (p->hits - (p->doubles + p->triples + p->home_runs)) / (float) effective_plate_appearances(p);
}

float double_percentage(player_t *p) {
  return p->doubles / (float) effective_plate_appearances(p);
}

float triple_percentage(player_t *p) {
  return p->triples / (float) effective_plate_appearances(p);
}

float home_run_percentage(player_t *p) {
  return p->home_runs / (float) effective_plate_appearances(p);
}

float avg_base_rating(player_t *p) {
  return walk_percentage(p) +
    single_percentage(p) +
    (2 * double_percentage(p))+
     (3 * triple_percentage(p)) +
      (4 * home_run_percentage(p));
}

void normalize_name(char *name) {
  size_t len = strlen(name);
  char last = name[len - 1];
  if (last == '#' || last == '*')
    name[len - 1] = '\0';
}

void destroy_player(player_t *p) {
  free(p);
}

player_t * create_player(char **stats) {
  player_t *p = malloc(sizeof(player_t));
  if (p == NULL) {
    exit(errno);
  }
  normalize_name(stats[0]);
  strcpy(p->name, stats[0]);
  p->age = atoi(stats[1]);
  strcpy(p->team, stats[2]);
  strcpy(p->league, stats[3]);
  p->g = atoi(stats[4]);
  p->plate_appearances = atoi(stats[5]);
  p->at_bat = atoi(stats[6]);
  p->runs = atoi(stats[7]);
  p->hits = atoi(stats[8]);
  p->doubles = atoi(stats[9]);
  p->triples = atoi(stats[10]);
  p->home_runs = atoi(stats[11]);
  p->runs_batted_in = atoi(stats[12]);
  p->stolen_bases = atoi(stats[13]);
  p->caught_stealing = atoi(stats[14]);
  p->walks = atoi(stats[15]);
  p->strikeouts = atoi(stats[16]);
  p->batting_avg = atof(stats[17]);
  p->onbase_percentage = atof(stats[18]);
  p->slugging_percentage = atof(stats[19]);
  p->onbase_plus_slugging = atof(stats[20]);
  p->ops_plus = atoi(stats[21]);
  p->total_bases = atoi(stats[22]);
  p->gdp = atoi(stats[23]);
  p->hit_by_pinch = atoi(stats[24]);
  p->sh = atoi(stats[25]);
  p->sacrifice_fly = atoi(stats[26]);
  p->intentional_walk = atoi(stats[27]);
  strcpy(p->position, stats[28]);
  return p;
}
