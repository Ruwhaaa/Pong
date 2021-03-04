##
## EPITECH PROJECT, 2017
## Mathematics - OCLOO
## File description:
## 101pong - Makefile
##

SRC	=	main.c			\
		antierror.c		\
		lib/my/my_strlen.c	\
		lib/my/my_getnbr_comma.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

LDFLAGS	=	-lm

NAME	=	101pong

$(NAME):	 $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
