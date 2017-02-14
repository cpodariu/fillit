NAME = fillit

SRC = backtracking.c fillmap.c main.c read_file.c tetrimino_functions.c \
tetrimino_functions2.c

OBJ = $(SRC:.c=.o)

HEAD =  fillitlib.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
