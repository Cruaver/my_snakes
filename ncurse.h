#ifndef NCURSE_H_
# define NCURSE_H_

#include <ncurses.h>


Direction * get_next_move(Direction * previous);

void display_points(PointList *snake, const chtype symbol);

#endif