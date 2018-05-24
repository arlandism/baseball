struct player {
  char name[100];
  int base_on_balls;
  int at_bat;
  int strikeouts;
};

int effective_plate_appearances(struct player p);
float strikeout_percentage(struct player p);
