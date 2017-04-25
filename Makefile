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


CFLAGS      = 	 -lncurses -Wall -Werror -Wpedantic -fPIC

SRCS        =	 main.c     \
                 game.c     \
                 my_tools.c \
                 ncurse.c

OBJS        =	 $(SRC:.c=.o)

all         :	 $(NAME)

$(NAME)     :	 $(OBJS)
		         $(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean       :    rm -f $(OBJS)

fclean      :    clean
				 rm -f $(NAME) *~

re          :    fclean all

.PHONY      :    all re clean fclean