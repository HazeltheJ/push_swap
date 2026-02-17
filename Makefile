# Variables
NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Dossiers
SRC_DIR		= src
INC_DIR		= includes
LIBFT_DIR	= includes/libft
LIBFT_INC	= $(LIBFT_DIR)/includes
LIBFT_A		= $(LIBFT_DIR)/libft.a

# Fichiers sources
SRCS		= main.c \
			  $(SRC_DIR)/parsing/check_args.c \
			  $(SRC_DIR)/parsing/check_nbr.c \
			  $(SRC_DIR)/parsing/init.c \
			  $(SRC_DIR)/manage_stack/fill_stack.c \
			  $(SRC_DIR)/manage_stack/sorts.c \
			  $(SRC_DIR)/manage_stack/chunk_sort.c \
			  $(SRC_DIR)/manage_stack/free_utils.c \
			  $(SRC_DIR)/manage_stack/utils_stack.c \
			  $(SRC_DIR)/operations/push.c \
			  $(SRC_DIR)/operations/reverse_rotate.c \
			  $(SRC_DIR)/operations/rotate.c \
			  $(SRC_DIR)/operations/swap.c 


OBJS		= $(SRCS:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
