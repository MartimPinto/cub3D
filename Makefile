NAME        = cub3D
NAME_BON	= cub3D_bonus
SRCS_DIR    = sources
SRCS_DIR_BON= sources_bonus
OBJ_DIR     = bin
OBJ_DIR_BON = bin_bonus
LIBFT_DIR   = Libft
LIBFT       = libft.a
MLX         = libmlx.a
SRCS        = $(wildcard $(SRCS_DIR)/*.c) $(wildcard $(SRCS_DIR)/**/*.c)
SRCS_BON	= $(wildcard $(SRCS_DIR_BON)/*.c) $(wildcard $(SRCS_DIR_BON)/**/*.c)
OBJS        = $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_BON	= $(patsubst $(SRCS_DIR_BON)/%.c,$(OBJ_DIR_BON)/%.o,$(SRCS_BON))
CCFLAGS     = -Wall -Wextra -Werror -g -I includes -std=c99
INC         = includes
OS			= linux

GREEN       = \033[38;5;47m
YELLOW      = \033[38;5;226m
RED         = \033[38;5;196m
CYAN        = \033[1;36m
RESET       = \033[0m

ifeq ($(MODE), debug)
    FLAGS += -fsanitize=address
endif

ifeq ($(OS), mac)
	MLX_DIR = mlx
	MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = mlx_linux
	MLXFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
	CCFLAGS += -I/usr/include -I$(MLX_DIR) -O3 -D LINUX
endif


$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@cc $(CCFLAGS) -c $< -o $@
	@echo "[$(CYAN)compiling$(RESET)]:\t $<"

$(OBJ_DIR_BON)/%.o: $(SRCS_DIR_BON)/%.c | $(OBJ_DIR_BON)
	@cc $(CCFLAGS) -c $< -o $@
	@echo "[$(CYAN)compiling$(RESET)]:\t $<"

all: $(NAME)
	@echo "[$(GREEN)DONE$(RESET)]:\t\t $(GREEN)$(NAME)$(RESET)"

bonus: $(NAME_BON)
	@echo "[$(GREEN)DONE$(RESET)]:\t\t $(GREEN)$(NAME_BON)$(RESET)"

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	cc $(CCFLAGS) -I $(INC) $(OBJS) $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT) $(MLXFLAGS) -o $(NAME)

$(NAME_BON): $(OBJS_BON) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	cc $(CCFLAGS) -I $(INC) $(OBJS_BON) $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT) $(MLXFLAGS) -o $(NAME_BON)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)/
	@mkdir $(OBJ_DIR)/init_exit
	@mkdir $(OBJ_DIR)/events
	@mkdir $(OBJ_DIR)/render
	@mkdir $(OBJ_DIR)/utils
	@mkdir $(OBJ_DIR)/parser

$(OBJ_DIR_BON):
	@mkdir $(OBJ_DIR_BON)/
	@mkdir $(OBJ_DIR_BON)/init_exit
	@mkdir $(OBJ_DIR_BON)/events
	@mkdir $(OBJ_DIR_BON)/render
	@mkdir $(OBJ_DIR_BON)/utils
	@mkdir $(OBJ_DIR_BON)/parser


$(LIBFT_DIR)/$(LIBFT):
	@echo "[$(CYAN)compiling$(RESET)]:\t $@"
	@make -C $(LIBFT_DIR)

$(MLX_DIR)/$(MLX):
	@echo "[$(CYAN)compiling$(RESET)]:\t $@"
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BON)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(YELLOW)Removing objects files$(RESET)"

fclean: clean
	@rm -rf $(NAME) $(NAME_BON)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(MLX_DIR)/$(MLX)
	@echo "$(RED)removing $(NAME) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re error
