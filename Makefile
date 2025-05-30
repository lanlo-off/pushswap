SRCS_A = push_swap.c\
	valid_arg.c\
	

SRC_DIR	= .

OBJS_A = $(SRCS_A:.c=.o)

INC_DIR	= .

NAME = libpushswap.a

HEADER = ft_pushswap.h

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_A) 
	$(AR) $(NAME) $(OBJS_A)

%.o: %.c $(HEADER)
	$(CC) -I. $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_A) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all
