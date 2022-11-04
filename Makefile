
NAME = push_swap

BONUS = checker

SRC = main.c alloc_free.c handle_errors.c push_swap.c push_swap_utils.c \
			sort_5.c push.c rotate.c rev_rotate.c swap.c

SRC_BONUS = checker.c alloc_free.c handle_errors.c push.c \
			rotate.c rev_rotate.c swap.c push_swap_utils.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

COMPILE = $(CC) $(CFLAGS)

FT_PRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME):
	make -C ./ft_printf
	$(COMPILE) -g $(SRC) $(FT_PRINTF) -o $(NAME)

bonus:
	make -C ./ft_printf
	$(COMPILE) -g $(SRC_BONUS) $(FT_PRINTF) -o $(BONUS)

clean:
	make clean -C ./ft_printf

fclean:	clean
	make fclean -C ./ft_printf
	rm -f $(NAME) 

re: fclean all

rebo: fclean all bonus

.PHONY: all clean fclean re bonus rebo
