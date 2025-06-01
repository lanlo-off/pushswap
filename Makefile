SRCS = src/push_swap.c\
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

CFLAGS = -Wall -Wextra -Werror

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
