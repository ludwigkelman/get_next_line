NAME = get_next_line.a

CC = cc
CFLAGS = -g -O0 -Wall -Werror -Wextra

HEADER = get_next_line.h

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
