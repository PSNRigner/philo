##
## Makefile for  in /home/frasse_l/Projets/PSU_2015_philo
## 
## Made by loic frasse-mathon
## Login   <frasse_l@epitech.net>
## 
## Started on  Mon Feb 29 12:23:03 2016 loic frasse-mathon
## Last update Tue Mar  1 19:16:46 2016 loic frasse-mathon
##

NAME		= philo

SRC		= src/main.c \
		src/sleep.c

LIB		= libriceferee.so

OBJ		= $(SRC:.c=.o)

LDFLAGS		= -L./lib -lriceferee -lpthread

CFLAGS		= -W -Wall -Werror -Wextra -I./include

CC		= gcc

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
