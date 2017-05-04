#include "backend.h"
#include "frontend.h"
#include <ncurses.h>

int main() {

    int i;
    int xmax;
    int ymax;
    enum Direction dir;
    enum Status status;
    Board *board;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);
    getmaxyx(stdscr, ymax, xmax);
    dir = RIGHT;
    board = create_board(create_snake(), NULL, xmax, ymax);
    for (i = 0; i < 6; i++) {
        add_new_food(board);
    }

    while (true) {
        clear();
        display_points(board->snake, ACS_CKBOARD);
        display_points(board->foods, ACS_DIAMOND);
        refresh();
        dir = get_next_move(dir);
        status = move_snake(board, dir);
        if (status == FAILURE)
            break;
    }
    endwin();
    return 0;
}

