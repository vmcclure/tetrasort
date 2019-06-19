NAME = fillit.out
SRC = fillit.c get_next_line.c libft/*.c

OUT = *.o
FLAGS = -Wall -Wextra -Werror
INC = *.h

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC) -I $(INC)
clean:
	rm -f $(OUT)
fclean:	clean
	rm -f $(NAME)
re: 	fclean all