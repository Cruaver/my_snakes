##
## Makefile for my_printf in /home/charbel/kabro_c/my
##
## Made by KABRO charbel
## Login   <kabro_c@etna-alternance.net>
##
## Started on  Tue Mar 21 09:44:38 2017 KABRO charbel
## Last update Wed Mar 22 08:44:51 2017 KABRO charbel
##

NAME        =    my_Snake

CC          = 	 gcc

RM          =    rm -rf

CFLAGS      = 	 -lncurses -Wall -Werror -Wpedantic

SRC         =	 main.c     \
                 game.c     \
                 ncurse.c	\
                 my_tools.c

OBJS        =	 $(SRC:.c=.o)

all:			 $(NAME)

$(NAME):		 $(OBJS)
				 $(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
				 $(RM) $(OBJS)

fclean:			 clean
				 $(RM) $(NAME) *~

re:				 fclean all

.PHONY:			 all re clean fclean