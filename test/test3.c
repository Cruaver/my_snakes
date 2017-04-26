#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    WINDOW *boite;

    initscr();
    boite= subwin(stdscr, 10, 10, LINES / 2, COLS /2);

    box(boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    refresh();

    getch();
    endwin();

    free(boite);

    return 0;

}