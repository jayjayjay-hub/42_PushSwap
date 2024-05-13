NAME = push_swap
LIBFT_NAME = libft
LIBFT_DIR = libft/
INCLUDE_DIR = include/
INCLUDE = -I $(INCLUDE_DIR)
LIBFT_INCLUDE = -I $(LIBFT_DIR)$(INCLUDE_DIR)
SRC_DIR = src/
OBJ_DIR = .obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf
NORM = norminette

SRC_FILES = main.c\
			push_swap.c\
			error.c\
			utils.c\
			command_utils.c\
			command_utils2.c\
			command_utils3.c\
			stack_management.c\
			sort.c\
			swap.c\
			rotate.c\
			reverse_rotate.c\
			push.c\
			stack_checker.c\
			stack_info.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)

SRCS += $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS += $(addprefix $(OBJ_DIR), $(OBJ_FILES))


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

norm:
	@echo "↓↓↓ push_swap error count ↓↓↓"
	@norminette $(SRC_FILES) $(INCLUDE) | grep Error | wc -l
	@norminette $(SRC_FILES) $(INCLUDE) | grep Error || ture

.PHONY: all clean fclean re norm
