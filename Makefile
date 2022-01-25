NAME	=   push_swap
HEADER  =   header.h

SRC_UTL = $(shell ls ./*.c) 

SRCS		=	$(SRC_UTL)

OBG		=	$(SRCS:%.c=%.o)

CFLAGS	= -Wall -Wextra -Werror 
RM		= rm -rf
CC		= gcc

all:			$(NAME)

$(NAME):		${OBG} $(HEADER)
				$(CC) $(CFLAGS)  -o $(NAME) ${OBG} libft/libft.a

libft/libft.a:	
				@$(MAKE) -C libft/
%.o: 			%.c	
				$(CC) $(CFLAGS) -I./ -c $< -o $@

fclean:			clean
				$(RM) $(NAME)

clean:
				$(RM) ${OBG}

re:				fclean all

.PHONY: clean fclean re all