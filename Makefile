##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

FLA = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME	=	my_paint

all:	comp_lib comp

comp_lib:
	make re -C lib/my $(FLA)
comp:	$(OBJ)
	gcc $(SRC) -L. -lmy -o $(NAME) $(FLA)

clean:
	rm -f $(OBJ)
	make clean -C lib/my
	rm -r *.a

fclean:	clean
	rm -f $(NAME)
	rm -f *.a
	make fclean -C lib/my

re:	fclean all
