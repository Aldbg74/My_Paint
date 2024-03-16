##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile lib
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

H_NAME	=	my.h

H_P_N = my_p.h

all:	$(NAME) copy_header

$(NAME):	create_lib copy_lib

create_lib:	$(OBJ)
	ar rc $(NAME) $(OBJ)

copy_lib:
	cp $(NAME) ../..

copy_header:
	cp $(H_NAME) ../../include
	cp $(H_P_N) ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) ../../$(NAME)

re:	fclean all
