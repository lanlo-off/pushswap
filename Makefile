SRCS = src/choose_rot.c\
	src/cost_rot.c\
	src/cost_utils.c\
	src/ft_free.c\
	src/init_stack.c\
	src/main.c\
	src/manip_lst.c\
	src/manip_lst2.c\
	src/push.c\
	src/rev_rotate.c\
	src/rotate.c\
	src/sort.c\
	src/swap.c

OBJS := $(SRCS:.c=.o)

NAME = push_swap

HEADER = src/push_swap.h

CC = cc -g

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g

TEST_FILES = test_index.c\
	src/choose_rot.c\
	src/cost_rot.c\
	src/ft_free.c\
	src/init_stack.c\
	src/manip_lst.c\
	src/manip_lst2.c\
	src/push.c\
	src/rev_rotate.c\
	src/rotate.c\
	src/swap.c\
	src/sort.c\
	src/cost_utils.c

all: $(NAME)

$(NAME): libs $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -L./ftprintf -lftprintf -g -o $(NAME)

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
	$(CC) $(CFLAGS) $(TEST_FILES) -I./src -I./libft -I./ftprintf -L./libft -lft -L./ftprintf -lftprintf -o test_index && ./test_index

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l