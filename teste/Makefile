##
## Makefile for my_snake in /home/ck/Desktop/my_snakes/teste
## 
## Made by KABRO charbel
## Login   <kabro_c@etna-alternance.net>
## 
## Started on  Thu May  4 09:59:54 2017 KABRO charbel
## Last update Thu May  4 10:00:41 2017 KABRO charbel
##

NAME        =    snake

CC          = 	 gcc

RM          =    rm -rf

CFLAGS      = 	 -lncurses -Wall -Werror -Wpedantic

SRC         =	 main.c     \
                 backend.c     \
                 frontend.c

OBJS        =	 $(SRC:.c=.o)

all:		 $(NAME)

$(NAME):	 $(OBJS)
		 $(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		 $(RM) $(OBJS)

fclean:		 clean
		 $(RM) $(NAME) *~

re:		 fclean all

.PHONY:		 all re clean fclean
