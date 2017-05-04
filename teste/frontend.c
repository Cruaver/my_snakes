#include <ncurses.h>
#include "backend.h"
#include "frontend.h"

int display_points(PointList *snake, const chtype symbol) {
    while (snake) {
        mvaddch(snake->y, snake->x, symbol);
        snake = snake->next;
    }
    return 0;
}

enum Direction get_next_move(enum Direction previous) {
    int ch;
    ch = getch();
    switch (ch) {
        case KEY_LEFT:
            if (previous != RIGHT) return LEFT;
        case KEY_RIGHT:
            if (previous != LEFT) return RIGHT;
        case KEY_DOWN:
            if (previous != UP) return DOWN;
        case KEY_UP:
            if (previous != DOWN) return UP;
        default:
            return previous;
    }
}