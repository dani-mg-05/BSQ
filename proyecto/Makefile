NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c errors.c ft_split.c ft_str.c parse_map_header.c aux.c search.c
OBJS = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f *.o

fclean:		clean
				rm -f $(NAME)

re:			fclean all
