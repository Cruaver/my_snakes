#include "game.h"
#include "ncurse.h"
#include <ncurses.h>
#include "my_tools.h"

int main(int argc, char *argv[]) {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);

    if (argc < 0) {

        endwin();



    }

    int xmax;
    int ymax;
    getmaxyx(stdscr, ymax, xmax);
    enum Direction dir = RIGHT;

    Game *game = create_game(create_snake(), NULL, xmax, ymax);
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
        enum Status status = move_snake(game, dir);
        if (status == FAILURE) break;
    }
    endwin();

    return 0;
}
