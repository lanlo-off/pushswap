SRCS = src/main.c\
	src/init_stack.c\
	src/manip_lst.c\
	src/ft_free.c\
	src/swap.c\
	src/rotate.c\
	src/push.c\
	src/rev_rotate.c\

OBJS := $(SRCS:.c=.o)

NAME = push_swap

HEADER = src/push_swap.h

CC = cc -g

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g

TEST_FILES = test_index.c\
	src/init_stack.c\
	src/manip_lst.c\
	src/ft_free.c\
	src/swap.c\
	src/rotate.c\
	src/push.c\
	src/rev_rotate.c\

all: $(NAME)

$(NAME): libs $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -L./ftprintf -lftprintf -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -I./libft -I./ftprintf $(CFLAGS) -c $< -o $@

libs:
	make -C libft
	make -C ftprintf

clean:
	@make clean -C libft
	@make clean -C ftprintf
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@make fclean -C ftprintf
	rm -f $(NAME)

re: fclean all

test: all
#	cc -g -Wall -Wextra -Werror test_index.c src/init_stack.c src/manip_lst.c src/swap.c src/rotate.c src/rev_rotate.c -I./src -I./libft -I./ftprintf -L./libft -lft -L./ftprintf -lftprintf -o test_index && ./test_index
	$(CC) $(CFLAGS) $(TEST_FILES) -I./src -I./libft -I./ftprintf -L./libft -lft -L./ftprintf -lftprintf -o test_index && ./test_index
