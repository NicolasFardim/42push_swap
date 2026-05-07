NAME	= push_swap

FLAGS	= -Wall -Werror -Wextra -fsanitize=address -g
LFLAGS	= -I libft
CC		= cc

LIBFT	= libft/libft.a

SRCS	=	main.c parser.c

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(LFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) $(LFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
