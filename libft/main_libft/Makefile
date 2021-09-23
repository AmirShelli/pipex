FLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
HEADER = libft.h
NAME = libft.a
.PHONY: all clean fclean bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)
.c.o: $(BNS) $(SRCS)
	gcc $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(BNO)
fclean: clean
	rm -f $(NAME)
re: fclean all 
