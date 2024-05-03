# Project name and the output archive file
NAME 		=	libft.a

# Directories
SRC_DIR		=	.
OBJ_DIR 	=	obj
INCLUDES 	= 	-I includes

# Compiler and flags
CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

# List of source files
SRC_FILES	=	$(wildcard $(SRC_DIR)/srcs_libft/*.c) \
            	$(wildcard $(SRC_DIR)/get_next_line/*.c) \
            	$(wildcard $(SRC_DIR)/ft_printf/*.c)

# List of object files
OBJ_FILES 	=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))


all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Removing libft objects files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)removing $(NAME) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re