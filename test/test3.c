#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    WINDOW *boite;

    initscr();
    boite= subwin(stdscr, LINES, COLS, 0, 0);
    wborder(boite, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(boite);
    refresh();

    getch();
    endwin();

    free(boite);

    return 0;

}
