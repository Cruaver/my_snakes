#include "backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int remove_from_list(PointList *elt, PointList **list) {
    PointList *currP, *prevP;
    prevP = NULL;

    for (currP = *list;
         currP != NULL;
         prevP = currP, currP = currP->next) {
        if (is_same_place(currP, elt)) {
            if (prevP == NULL) {
                *list = currP->next;
            } else {
                prevP->next = currP->next;
            }
            free(currP);
            return 1;
        }
    }
    return 0;
}

enum Status move_snake(Board *board, enum Direction dir) {
    PointList *end;
    PointList *beginning;

    beginning = next_move(board, dir);
    if (beginning == NULL) {
        return FAILURE;
    }
    if (board->snake->next && is_same_place(beginning, board->snake->next) == 1) {
        beginning->next = NULL;
        free(beginning);
        return SUCCESS;
    }
    if (list_contains(beginning, board->snake) == 1) {
        return FAILURE;
    }
    if (list_contains(beginning, board->foods) == 1) {
        beginning->next = board->snake;
        board->snake = beginning;
        remove_from_list(beginning, &(board->foods));
        add_new_food(board);

        return SUCCESS;
    }
    beginning->next = board->snake;
    board->snake = beginning;
    end = board->snake;
    while (end->next->next) {
        end = end->next;
    }
    free(end->next);
    end->next = NULL;

    return SUCCESS;
}

int is_same_place(PointList *cell1, PointList *cell2) {
    if (cell1->x == cell2->x && cell1->y == cell2->y)
        return 1;
    return 0;
}


PointList *next_move(Board *board, enum Direction dir) {
    PointList *snake = board->snake;
    int new_x = snake->x;
    int new_y = snake->y;
    switch (dir) {
        case UP:
            new_y = snake->y - 1;
            break;
        case DOWN:
            new_y = snake->y + 1;
            break;
        case LEFT:
            new_x = snake->x - 1;
            break;
        case RIGHT:
            new_x = snake->x + 1;
            break;
    }
    if (new_x < 0 || new_y < 0 || new_x >= board->xmax || new_y >= board->ymax) {
        return NULL;
    } else {
        return create_cell(new_x, new_y);
    }
}

PointList *create_random_cell(int xmax, int ymax) {
    return create_cell(rand() % xmax, rand() % ymax);
}

void add_new_food(Board *board) {
    PointList *new_food;
    do {
        new_food = create_random_cell(board->xmax, board->ymax);
    } while (list_contains(new_food, board->foods) == 1 || list_contains(new_food, board->snake) == 1);
    new_food->next = board->foods;
    board->foods = new_food;
}

int list_contains(PointList *cell, PointList *list) {
    PointList *s = list;
    while (s) {
        if (is_same_place(s, cell) == 1) {
            return 1;
        }
        s = s->next;
    }
    return 0;
}

PointList *create_cell(int x, int y) {
    PointList *cell = malloc(sizeof(*cell));
    cell->x = x;
    cell->y = y;
    cell->next = NULL;
    return cell;
}

Board *create_board(PointList *snake, PointList *foods, int xmax, int ymax) {
    Board *board = malloc(sizeof(*board));
    board->foods = foods;
    board->snake = snake;
    board->xmax = xmax;
    board->ymax = ymax;
    return board;
}

PointList *create_snake() {
    PointList *a = create_cell(2, 3);
    PointList *b = create_cell(2, 2);
    a->next = b;
    return a;
}