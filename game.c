#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int remove_from_list(PointList *maillon, PointList **list) {
    PointList *currP, *prevP;
    prevP = NULL;

    for (currP = *list; currP != NULL; prevP = currP, currP = currP->next) {
        if (is_same_place(currP, maillon) == 1) {
            if (prevP == NULL)
                *list = currP->next;
            else
                prevP->next = currP->next;
            free(currP);
            return 0;
        }
    }
    return 1;
}

enum Status move_snake(Game *game, enum Direction dir) {
    PointList *end;
    PointList *beginning;

    beginning = next_move(game, dir->direction);
    if (beginning == NULL) {
        return FAILURE;
    }
    if (game->snake->next && is_same_place(beginning, game->snake->next) == 1) {
        beginning->next = NULL;
        free(beginning);
        return SUCCESS;
    }
    if (list_contains(beginning, game->snake) == 1) {
        return FAILURE;
    }

    if (list_contains(beginning, game->foods) == 1) {
        beginning->next = game->snake;
        game->snake = beginning;
        remove_from_list(beginning, &(game->foods));
        add_new_food(game);

        return SUCCESS;
    }
    beginning->next = game->snake;
    game->snake = beginning;

    end = game->snake;
    while (end->next->next) {
        end = end->next;
    }
    free(end->next);
    end->next = NULL;

    return SUCCESS;
}

int is_same_place(PointList *cell1, PointList *cell2) {
    if (cell1->x == cell2->x && cell1->y == cell2->y)
        return 0;
    return 1;
}


PointList *next_move(Game *game,  enum Direction dir) {
    PointList *snake;
    int new_x;
    int new_y;
    snake = game->snake;
    new_x = snake->x;
    new_y = snake->y;
    if (dir == UP)
        new_y = snake->y - 1;
    else if (dir == DOWN)
        new_y = snake->y + 1;
    else if (dir == LEFT)
        new_x = snake->x - 1;
    else if (dir == RIGHT)
        new_x = snake->x + 1;

    if (new_x < 0 || new_y < 0 || new_x >= game->xmax || new_y >= game->ymax)
        return NULL;
    else
        return create_cell(new_x, new_y);
}

PointList *create_random_cell(int xmax, int ymax) {
    return create_cell(rand() % xmax, rand() % ymax);
}

void add_new_food(Game *game) {
    PointList *new_food;
    new_food = create_random_cell(game->xmax, game->ymax);

    while (list_contains(new_food, game->foods) == 1 || list_contains(new_food, game->snake) == 1) {
        new_food->next = game->foods;
        game->foods = new_food;
    }
}

int list_contains(PointList *cell, PointList *list) {
    PointList *s = list;
    while (s) {
        if (is_same_place(s, cell) == 1) {
            return 0;
        }
        s = s->next;
    }
    return 1;
}

PointList *create_cell(int x, int y) {
    PointList *cell = malloc(sizeof(*cell));
    cell->x = x;
    cell->y = y;
    cell->next = NULL;
    return cell;
}

Game *create_game(PointList *snake, PointList *foods, int xmax, int ymax) {
    Game *game = malloc(sizeof(*game));
    game->foods = foods;
    game->snake = snake;
    game->xmax = xmax;
    game->ymax = ymax;
    return game;
}

PointList *create_snake() {
    PointList *a = create_cell(2, 3);
    PointList *b = create_cell(2, 2);
    a->next = b;
    return a;
}

