#include <ncurses.h>
#include "game.h"
#include "ncurse.h"
#include "my_tools.h"

void display_points(PointList *snake, const chtype symbol) {
    while (snake) {
        boite= subwin(stdscr, LINES , COLS , 0, 0);
        wborder(boite, '|', '|', '-', '-', '+', '+', '+', '+');
        wrefresh(boite);
        mvaddch(snake->y, snake->x, symbol);
        snake = snake->next;
    }
}

enum Direction get_next_move(enum Direction previous) {
    int ch = getch();
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


