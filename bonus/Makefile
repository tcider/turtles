NAME = dummy_turtles

SRC = *.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: clean all
