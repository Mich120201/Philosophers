# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 10:08:37 by mvolpi            #+#    #+#              #
#    Updated: 2022/09/27 12:03:50 by mvolpi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_MAIN = src/philosopher.c

SRC_PH = src/philo/errors.c \
			src/philo/utils.c \

LIBFT  = libft/libft.a

FLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

OBJ = $(SRC_MAIN:src/%.c=$(OBJ_DIR)/%.o)\
		$(SRC_PH:src/push_swap/%.c=$(OBJ_DIR)/push_swap/%.o)\

all: $(NAME)

clean:
	@echo "     - Removing push_swap object files..."
	@rm -rf $(OBJ_DIR)
	@echo "          push_swap OBJ deleted"
	@make -C libft clean

fclean: clean
	@echo "     - Removing $(NAME)..."
	@rm -rf $(NAME)
	@echo "          $(NAME) *.a deleted"
	@make -C libft fclean

re: fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@mkdir obj/push_swap
	@mkdir obj/array_moves

$(OBJ_DIR)/%.o : src/%.c 
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/push_swap/%.o : src/push_swap/%.c 
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "     - Making libft..."
	@make -s -C libft
	@echo "     - Making $(NAME)..."
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "          $(NAME) created"
	@echo "     - Compiled -"

norm: 
	@norminette -R CheckForbiddenSourceHeader

.PHONY : all clean fclean re
