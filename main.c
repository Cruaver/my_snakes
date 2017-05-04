#include "game.h"
#include "ncurse.h"
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int xmax;
    int ymax;
    int i;
    Direction * direction;
    Status * status;
    Game * game;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(10);
    direction = "RIGHT";
    game = create_game(create_snake(), NULL, xmax, ymax);
    for (i = 0; i < 6; i++) {
        add_new_food(game);
    }

    while (true) {
        clear();
        display_points(game->snake, ACS_BLOCK);
        display_points(game->foods, ACS_DIAMOND);
        refresh();
        dir = get_next_move(Direction * direction);
        status = move_snake(game,  * direction);
        if (status == FAILURE)
            break;
    }
    endwin();
    free(boite);
    return 0;
}
