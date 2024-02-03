# Makefile

NAME := push_swap
CC := gcc

SRC_DIR := ./
INC_DIR := ./inc
LIBFT_INC_DIR := ./libft/inc
OBJ_DIR := ./build

CFLAGS := -Wall -Wextra -Werror

STATIC_LIBFT := libft/libft.a

FILES := push_swap.c \
	dupli_ctrl.c \
	input_ctrl.c \
	limit_ctrl.c \
	linked_list_mgt.c \
	linked_list_utili.c \
	mini_sort.c \
	push.c \
	quicksort.c \
	reverse.c \
	rotate.c \
	sort_2.c \
	sort_5.c \
	sort_rank.c \
	sort_rank_2.c\
	sort_utili.c\
	sort_utili_2.c\
	swap.c
SRC := $(addprefix $(SRC_DIR)/, $(FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all : $(NAME)

# Build push_swap executable
$(NAME): $(STATIC_LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $@ $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) \
	$(STATIC_LIBFT)

# Compile source files from ./src into ./bin
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ \
	-I $(INC_DIR) \
	-I $(LIBFT_INC_DIR)

# Build libft.a using its Makefile
$(STATIC_LIBFT):
	$(MAKE) -C libft all

clean :
	rm -f $(OBJ_DIR)/*.o
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY: all clean fclean 