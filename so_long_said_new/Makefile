SRC_FILE = so_long.c so_long_utils.c handl_error.c handl_error_utils.c\
			put_image.c evente.c animation.c g_n_l/get_next_line.c g_n_l/get_next_line_utils.c
NAME = so_long
OBJ_FILE = $(SRC_FILE:.c=.o)
HEADER = so_long.h
CC = cc
RM = rm -rf

MLX_DIR = ./minilibx_opengl_20191021
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS = -I$(MLX_DIR)

PURPLE = \033[0;35m
BLUE = \033[0;34m
RED = \033[0;31m

LIBTF_PATH = ./libft
LIBFT = $(LIBTF_PATH)/libft.a

all : $(NAME) LIBFT

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@make -C $(LIBTF_PATH) --silent
	@$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME) $(MLX_FLAGS) $(LIBFT)
	@echo "$(BLUE)TOUT EST MAKE"

clean :
	@$(RM) $(OBJ_FILE)
	@make -C $(LIBTF_PATH) clean
	@echo "$(RED) TOUT EST CLEAR"

fclean : clean
	@$(RM) $(NAME)
	@make -C $(LIBTF_PATH) fclean

re : fclean all