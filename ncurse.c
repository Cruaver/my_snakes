#include <ncurses.h>
#include "game.h"
#include "ncurse.h"

void display_points(PointList *snake, const chtype symbol) {
    while (snake) {
        mvaddch(snake->y, snake->x, symbol);
        snake = snake->next;
    }
}

enum Direction get_next_move(enum Direction previous) {
    int ch = getch();
    if (ch == KEY_LEFT) {
        if (previous != RIGHT)
            return LEFT;
    } else if (ch == KEY_RIGHT) {
        if (previous != LEFT)
            return RIGHT;
    } else if (ch == KEY_DOWN) {
        if (previous != UP)
            return DOWN;
    } else if (ch == KEY_UP) {
        if (previous != DOWN)
            return UP;
    } else
        return previous;
}


