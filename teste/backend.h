/*
** backend.h for my_snake in /home/ck/Desktop/my_snakes/teste
** 
** Made by KABRO charbel
** Login   <kabro_c@etna-alternance.net>
** 
** Started on  Thu May  4 09:55:22 2017 KABRO charbel
** Last update Thu May  4 09:56:11 2017 KABRO charbel
*/

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
} Board;


int		is_same_place(PointList *cell1, PointList *cell2);

enum Status	move_snake(Board *board, enum Direction dir);

PointList	*next_move(Board *board, enum Direction dir);

PointList	*create_cell(int x, int y);

PointList	*create_random_cell(int xmax, int ymax);

PointList	*create_snake();

Board		*create_board(PointList *foods, PointList *snake, int xmax, int ymax);

int		list_contains(PointList *cell, PointList *list);

int		remove_from_list(PointList *maillon, PointList **list);

int		add_new_food(Board *board);
