#include <ncurses.h>
#include "game.h"
#include "ncurse.h"

void display_points(PointList *snake, const chtype symbol) {
    while (snake) {
        mvaddch(snake->y, snake->x, symbol);
        snake = snake->next;
    }
}

char *get_next_move(Direction *dir) {
    int ch = getch();
    if (ch == KEY_LEFT) {
        if (dir->previous != "RIGHT")
            return "LEFT";
    } else if (ch == KEY_RIGHT) {
        if (dir->previous != "LEFT")
            return "RIGHT";
    } else if (ch == KEY_DOWN) {
        if (dir->previous != "UP")
            return "DOWN";
    } else if (ch == KEY_UP) {
        if (dir->previous != "DOWN")
            return "UP";
    } else
        return dir->previous;
}


