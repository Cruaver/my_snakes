#include "backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool remove_from_list(PointList* elt, PointList** list) {
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
      return true;
    }
  }
  return false;
}

enum Status move_snake(Game* game, enum Direction dir) {
  // Create a new beginning. Check boundaries.
  PointList* beginning = next_move(game, dir);
  if (beginning == NULL) {
    return FAILURE;
  }

  // If we've gone backwards, don't do anything
  if (game->snake->next && is_same_place(beginning, game->snake->next)) {
    beginning->next = NULL;
    free(beginning);
    return SUCCESS;
  }

  // Check for collisions
  if (list_contains(beginning, game->snake)) {
    return FAILURE;
  }

  // Check for food
  if (list_contains(beginning, game->foods)) {
    // Attach the beginning to the rest of the snake;
    beginning->next = game->snake;
    game->snake = beginning;
    remove_from_list(beginning, &(game->foods));
    add_new_food(game);

    return SUCCESS;
  }

  // Attach the beginning to the rest of the snake
  beginning->next = game->snake;
  game->snake = beginning;


  // Cut off the end
  PointList* end = game->snake;
  while(end->next->next) {
    end = end->next;
  }
  free(end->next);
  end->next = NULL;

  return SUCCESS;
}

bool is_same_place(PointList* cell1, PointList* cell2) {
  return cell1->x == cell2->x && cell1->y == cell2->y;
}


PointList* next_move(Game* game, enum Direction dir) {
  PointList* snake = game->snake;
  int new_x = snake->x;
  int new_y = snake->y;
  switch(dir) {
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
  if (new_x < 0 || new_y < 0 || new_x >= game->xmax || new_y >= game->ymax) {
    return NULL;
  } else {
    return create_cell(new_x, new_y);
  }
}

PointList* create_random_cell(int xmax, int ymax) {
  return create_cell(rand() % xmax, rand() % ymax);
}

void add_new_food(Game* game) {
  PointList* new_food;
  do {
    new_food = create_random_cell(game->xmax, game->ymax);
  } while(list_contains(new_food, game->foods) || list_contains(new_food, game->snake));
  new_food->next = game->foods;
  game->foods = new_food;
}

bool list_contains(PointList* cell, PointList* list) {
  PointList* s = list;
  while (s) {
    if (is_same_place(s, cell)) {
      return true;
    }
    s = s->next;
  }
  return false;
}

PointList* create_cell(int x, int y) {
  PointList* cell = malloc(sizeof(*cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  return cell;
}

Game* create_board(PointList* snake, PointList* foods, int xmax, int ymax) {
  Game* game = malloc(sizeof(*game));
  game->foods = foods;
  game->snake = snake;
  game->xmax = xmax;
  game->ymax = ymax;
  return game;
}

PointList* create_snake() {
  PointList* a = create_cell(2,3);
  PointList* b = create_cell(2,2);
  a->next = b;
  return a;
}

