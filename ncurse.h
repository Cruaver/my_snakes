#ifndef NCURSE_H_
# define NCURSE_H_

#include <ncurses.h>
#include "game.h"


char *get_next_move(Direction *dir);

void display_points(PointList *snake, const chtype symbol);

#endif