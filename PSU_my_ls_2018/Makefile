##
## EPITECH PROJECT, 2019
## makefile my_ls
## File description:
## my_ls
##

NAME	=	my_ls

SRC	=	./src/main.c	\
		./src/file_info.c	\
		./src/file_info2.c	\
		./src/get_d.c	\
		./src/print_w_path.c	\
		./print/*.c	\

CFLAGS	=	-I ./include -g3

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
