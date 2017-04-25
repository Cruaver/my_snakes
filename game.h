#ifndef GAME_H_
# define GAME_H_

#include <stdbool.h>

enum Direction {
    UP, DOWN, LEFT, RIGHT
};
enum Status {
    SUCCESS, FAILURE
};

struct PointList {
    int x;
    int y;
    struct PointList *next;
};

typedef struct PointList PointList;

typedef struct {
    PointList *snake;
    PointList *foods;
    int xmax;
    int ymax;
} Game;


bool is_same_place(PointList *cell1, PointList *cell2);

enum Status move_snake(Game *game, enum Direction dir);

PointList *next_move(Game *game, enum Direction dir);

PointList *create_cell(int x, int y);

PointList *create_random_cell(int xmax, int ymax);

PointList *create_snake();

Game *create_game(PointList *foods, PointList *snake, int xmax, int ymax);

bool list_contains(PointList *cell, PointList *list);

bool remove_from_list(PointList *elt, PointList **list);

void add_new_food(Game *game);

#endif