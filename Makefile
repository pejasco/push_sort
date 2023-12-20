# Makefile

CC = gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT := libft/libft.a

NAME := libftprintf.a
CFILES := \
	ft_printf.c \
	ft_print_c.c \
	ft_print_s.c \
	ft_print_p.c \
	ft_print_d.c
OFILES := $(CFILES:.c=.o)

# Default target
all: $(NAME)

# Compile all codes from libft and libftprintf into libftprintf.a
$(NAME): $(LIBFT) $(OFILES)
	ar rcs $@ $(OFILES) libft/*.o

# Build all object files of libft as well as libft.a
$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	rm -f $(OFILES) $(CFILES:.c=.o)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
