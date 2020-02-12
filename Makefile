##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compilator
##

SRC	=	$(shell find . -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
