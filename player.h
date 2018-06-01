#ifndef PLAYER_H
#define PLAYER_H
typedef struct player {
  char *name;
  int age;
  char *team;
  char *league;
  int g;
  int plate_appearances;
  int at_bat;
  int runs;
  int hits;
  int doubles;
  int triples;
  int home_runs;
  int runs_batted_in;
  int stolen_bases;
  int caught_stealing;
  int walks;
  int strikeouts;
  int base_on_balls;
  float batting_avg;
  float onbase_percentage;
  float slugging_percentage;
  float onbase_plus_slugging;
  int ops_plus;
  int total_bases;
  int gdp; // gross domestic baseball product
  int hit_by_pinch;
  int sh;
  int sacrifice_fly;
  int intentional_walk;
  char *position;
} player_t;

int effective_plate_appearances(player_t p);
float strikeout_percentage(player_t p);
player_t create_player(char **stats);
#endif
