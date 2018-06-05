#include <stdio.h>
#include <string.h>
#include "player.h"
#include <errno.h>
#include <stdlib.h>
#include <math.h>

void teardown(player_t **players, int player_count) {
  for (int i = 0; i < player_count; i++) {
    destroy_player(players[i]);
  }
  free(players);
}

int create_players(FILE *file, player_t ***players) {
  char player_string[10000];
  char *stats[30];
  int num_players = 0;
  while ((fgets(player_string, 10000, file) != NULL)) {
    char *stat;
    int i = 0;
    char *ps_ptr = player_string;
    while ((stat = strsep(&ps_ptr, ",")) != NULL) {
      stats[i] = stat;
      i++;
    }
    if (num_players % 10 == 0) {
      size_t alloc_size = ((num_players + 10) * sizeof(player_t *));
      *players = realloc(*players, alloc_size);
      if (*players == NULL) {
        exit(errno);
      }
    }

    player_t *p = create_player(stats);
    (*players)[num_players] = p;

    num_players += 1;
  }
  return num_players;
}

void print_stats(player_t **players, int num_players) {
  player_t *lowest_strikeout = NULL;
  float lowest_strikeout_rate = INFINITY;

  player_t *toughest_out = NULL;
  float lowest_out_rate = INFINITY;

  player_t *highest_hrs = NULL;
  float highest_hr_rate = -INFINITY;

  player_t *best_batter = NULL;
  float best_abr = -INFINITY;

  for (int i = 0; i < num_players; i++) {
    player_t *p = players[i];
    float player_strikeout = strikeout_percentage(p);
    if (player_strikeout < lowest_strikeout_rate) {
      lowest_strikeout = p;
      lowest_strikeout_rate = player_strikeout;
    }

    float player_out_rate = out_percentage(p);
    if (player_out_rate < lowest_out_rate) {
      toughest_out = p;
      lowest_out_rate = player_out_rate;
    }

    float player_hr_rate = home_run_percentage(p);
    if (player_hr_rate > highest_hr_rate) {
      highest_hrs = p;
      highest_hr_rate = player_hr_rate;
    }

    float player_abr = avg_base_rating(p);
    if (player_abr > best_abr) {
      best_batter = p;
      best_abr = player_abr;
    }
  }
  printf("Lowest strikeout rate\n%s\t%.2f%%\n\n", lowest_strikeout->name, lowest_strikeout_rate * 100);
  printf("Toughest out rate\n%s\t%.2f%%\n\n", toughest_out->name, lowest_out_rate * 100);
  printf("Highest home run rate\n%s\t%.2f%%\n\n", highest_hrs->name, highest_hr_rate * 100);
  printf("Best batter player\n%s\t%f\n\n", best_batter->name, best_abr);
}

int main(int argc, const char * argv[]) {
  FILE *file = fopen(argv[1], "r");
  player_t ** players = NULL;
  int num_players = create_players(file, &players);
  print_stats(players, num_players);
  teardown(players, num_players);
  return 0;
}
