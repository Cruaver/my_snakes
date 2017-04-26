#include "game.h"
#include "ncurse.h"
#include <ncurses.h>
#include "my_tools.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int xmax;
    int ymax;
    int i;
    enum Direction dir;
    enum Status status;
    Game * game;
    WINDOW * boite;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(10);
    boite= subwin(stdscr, 10, 10, LINES / 2, COLS /2);
    box(boite, ACS_VLINE, ACS_HLINE);
    refresh();


    dir = RIGHT;
    getmaxyx(stdscr, ymax, xmax);
    game = create_game(create_snake(), NULL, xmax, ymax);
    for (i = 0; i < 6; i++) {
        add_new_food(game);
    }

    while (true) {
        clear();
        display_points(game->snake, ACS_BLOCK);
        display_points(game->foods, ACS_DIAMOND);
        refresh();
        dir = get_next_move(dir);
        status = move_snake(game, dir);
        if (status == FAILURE) break;

    }
    endwin();
    free(boite);

    return 0;
}
