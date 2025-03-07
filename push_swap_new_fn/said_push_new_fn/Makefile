NAME = push_swap
NAME_BONUS = checker

SRC_AID = handl_error.c creat_stack.c swap.c push.c rotate.c\
		reverse_rotate.c push_swap_utils.c small_stacks.c big_stacks.c big_stack_move.c

SRC = push_swap.c  $(SRC_AID)

SRC_BONUS =  checker.c checker_utils.c g_n_l/get_next_line.c g_n_l/get_next_line_utils.c $(SRC_AID)

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
HEADER = push_swap.h checker.h

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "TOUT EST MAKE"

bonus : $(OBJ_BONUS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT)
	@echo "TOUT BONUS EST MAKE"

clean :
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_PATH) fclean
	@echo "TOUT EST CLEAN"

re : fclean all

.PHONY : clean all