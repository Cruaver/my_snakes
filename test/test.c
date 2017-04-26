
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int xmax;
    int ymax;
    WINDOW * boite;

    getmaxyx(stdscr, ymax, xmax);
    initscr();
    boite = subwin(stdscr, 10, 10, ymax / 2, xmax / 2);

    box(boite, ACS_VLINE, ACS_HLINE);
    refresh();

    getch();
    endwin();

    free(boite);

    return 0;
}
