#include "game.h"
#include "ncurse.h"
#include <ncurses.h>
#include "my_tools.h"

int main(int argc, char *argv[]) {

    int xmax;
    int ymax;
    enum Direction dir;
    enum Status status;
    Game * game;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(10);

    dir = RIGHT;
    getmaxyx(stdscr, ymax, xmax);
    game = create_game(create_snake(), NULL, xmax, ymax);
    int i;
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

    return 0;
}
