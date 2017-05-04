#ifndef NCURSE_H_
# define NCURSE_H_

#include <ncurses.h>
#include "game.h"


enum Direction get_next_move(enum Direction previous);

int display_points(PointList *snake, const chtype symbol);

#endif