/*
** frontend.h for my_snake in /home/ck/Desktop/my_snakes/teste
** 
** Made by KABRO charbel
** Login   <kabro_c@etna-alternance.net>
** 
** Started on  Thu May  4 09:57:39 2017 KABRO charbel
** Last update Thu May  4 09:57:55 2017 KABRO charbel
*/

#include <ncurses.h>

enum Direction	get_next_move(enum Direction previous);
int		display_points(PointList *snake, const chtype symbol);
