#include "backend.h"
#include "frontend.h"
#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);

    int xmax;
    int ymax;
    getmaxyx(stdscr, ymax, xmax);
    enum Direction dir = RIGHT;

    Game *game = create_board(create_snake(), NULL, xmax, ymax);
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
