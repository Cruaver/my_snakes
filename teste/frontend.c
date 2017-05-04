/*
** frontend.c for my_snake in /home/ck/Desktop/my_snakes/teste
** 
** Made by KABRO charbel
** Login   <kabro_c@etna-alternance.net>
** 
** Started on  Thu May  4 09:56:26 2017 KABRO charbel
** Last update Thu May  4 09:57:24 2017 KABRO charbel
*/

#include <ncurses.h>
#include "backend.h"
#include "frontend.h"

int	display_points(PointList *snake, const chtype symbol)
{
  while (snake)
    {
      mvaddch(snake->y, snake->x, symbol);
      snake = snake->next;
    }
  return 0;
}

enum Direction	get_next_move(enum Direction previous)
{
  int		ch;
  
  ch = getch();
  switch (ch)
    {
    case KEY_LEFT:
      if (previous != RIGHT)
	return LEFT;
    case KEY_RIGHT:
      if (previous != LEFT)
	return RIGHT;
    case KEY_DOWN:
      if (previous != UP)
	return DOWN;
    case KEY_UP:
      if (previous != DOWN)
	return UP;
    default:
      return previous;
    }
}
