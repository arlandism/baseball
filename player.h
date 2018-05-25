struct player {
  char name[100];
  int age;
  char team[4];
  char league[2];
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
  float ba;
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
};

int effective_plate_appearances(struct player p);
float strikeout_percentage(struct player p);
