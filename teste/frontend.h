#include <ncurses.h>


enum Direction get_next_move(enum Direction previous);

int display_points(PointList *snake, const chtype symbol);