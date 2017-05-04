#ifndef GAME_H_
# define GAME_H_

struct PointList {
    int x;
    int y;
    struct PointList *next;
};

typedef struct PointList PointList;

typedef struct {
    char *direction;
    char *previous;
} Direction;

typedef struct {
    char *status;
} Status;


typedef struct {
    PointList *snake;
    PointList *foods;
    int xmax;
    int ymax;
} Game;

int is_same_place(PointList *cell1, PointList *cell2);

char *move_snake(Game *game, Direction *dir);

PointList *next_move(Game *game, Direction *dir);

PointList *create_cell(int x, int y);

PointList *create_random_cell(int xmax, int ymax);

PointList *create_snake();

Game *create_game(PointList *foods, PointList *snake, int xmax, int ymax);

int list_contains(PointList *cell, PointList *list);

int remove_from_list(PointList *maillon, PointList **list);

void add_new_food(Game *game);

#endif