NAME = get_next_line.a

CC = cc
	CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c

OBJS=$(SRCS:.c=.o)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

clean:
	rm -rf ${OBJS}


fclean: clean
	rm -rf $(NAME)

re: fclean all
