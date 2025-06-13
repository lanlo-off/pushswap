SRCS = src/choose_rot.c\
	src/cost_rot.c\
	src/cost_utils.c\
	src/free_and_error.c\
	src/init_stack.c\
	src/main.c\
	src/manip_lst.c\
	src/manip_lst2.c\
	src/push.c\
	src/pushswap.c\
	src/rev_rotate.c\
	src/rotate.c\
	src/sort.c\
	src/swap.c

SRCS_BONUS = bonus/apply_instr_bonus.c\
	bonus/get_next_line_utils.c\
	bonus/get_next_line.c\
	bonus/main_bonus.c\
	bonus/parser_bonus.c\
	src/choose_rot.c\
	src/cost_rot.c\
	src/cost_utils.c\
	src/free_and_error.c\
	src/init_stack.c\
	src/manip_lst.c\
	src/manip_lst2.c\
	src/push.c\
	src/pushswap.c\
	src/rev_rotate.c\
	src/rotate.c\
	src/sort.c\
	src/swap.c

OBJS := $(SRCS:.c=.o)

OBJS_BONUS := $(SRCS_BONUS:.c=.o)

NAME = push_swap

NAME_BONUS = checker

HEADER = src/push_swap.h

HEADER_BONUS = bonus/push_swap_bonus.h\
	bonus/get_next_line.h

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g

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
	rm -f $(OBJS_BONUS)

fclean: clean
	@make fclean -C libft
	@make fclean -C ftprintf
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

bonus: libs $(OBJS_BONUS) $(NAME)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L./libft -lft -L./ftprintf -lftprintf -o $(NAME_BONUS)

testbonus2: bonus
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	@echo -n "checker_linux: "
	@./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "checker_llechert: "
	@./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)

test2: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)

testbonus3: bonus
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	@echo -n "checker_linux: "
	@./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "checker_llechert: "
	@./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)


test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)

testbonus5: bonus
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	@echo -n "checker_linux: "
	@./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "checker_llechert: "
	@./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)

testbonus100: bonus
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	@echo -n "checker_linux: "
	@./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "checker_llechert: "
	@./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)

testbonus500: bonus
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	@echo -n "checker_linux: "
	@./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "checker_llechert: "
	@./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./$(NAME_BONUS) $(ARG)

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)