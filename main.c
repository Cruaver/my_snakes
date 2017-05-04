#include "game.h"
#include "ncurse.h"
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int xmax;
    int ymax;
    int i;
    Direction *dir;
    Status *stat;

    Game *game;

    initscr();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, ymax, xmax);
    curs_set(0);
    timeout(10);
    dir.direction = "RIGHT";
    game = create_game(create_snake(), NULL, xmax, ymax);
    for (i = 0; i < 6; i++) {
        add_new_food(game);
    }

    while (true) {
        clear();
        display_points(game->snake, ACS_BLOCK);
        display_points(game->foods, ACS_DIAMOND);
        refresh();
        dir.direction = get_next_move(dir.direction);
        stat.status = move_snake(game, dir.direction);
        if (stat.status == "FAILURE")
            break;
    }
    endwin();
    return 0;
}
