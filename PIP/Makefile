LIBFT = ./libft/main_libft/libft.a

NAME = pipex

SRCS =  $(wildcard ./src/*.c)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes

CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) all -C ./libft/main_libft
	@$(CC) -o $(NAME) $(LIBFT) $(OBJS)

clean :
	@rm -rf $(wildcard ./*.o)
	@rm -rf $(wildcard ./*/*.o)
	@rm -rf $(wildcard ./*/*/*.o)

fclean : clean
	@$(MAKE) fclean -C ./libft/main_libft
	@rm -rf $(NAME)

re : fclean all