NAME 	=	push_swap
HEADER  =   header.h
SOURCES = 	valid_params.c \
			main.c \
			actions_1.c \
			actions_2.c \
			arrayFunc.c \
			push_swap.c \
			rank.c \
			srank.c \
			rules.c \
			mini_sort.c \
			test.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) libft/libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re