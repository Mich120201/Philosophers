# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:34:22 by mvolpi            #+#    #+#              #
#    Updated: 2022/10/10 10:47:41 by mvolpi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_MAIN = src/philosophers.c

SRC_PH = src/philo/errors.c \
			src/philo/ft_split.c \
			src/philo/initialization.c \
			src/philo/life.c \
			src/philo/moves.c \
			src/philo/print.c \
			src/philo/utils_2.c \
			src/philo/utils.c \

FLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

OBJ = $(SRC_MAIN:src/%.c=$(OBJ_DIR)/%.o)\
		$(SRC_PH:src/philo/%.c=$(OBJ_DIR)/philo/%.o)

all: $(NAME)

clean:
	@echo " -Removing philo object file..."
	@rm -rf	$(OBJ_DIR)
	@echo "		PHILO OBJ FILE DELETED"

fclean:
	@echo " -Removing $(NAME)..."
	@rm -rf	$(NAME)
	@echo "		$(NAME) *.a DELETED"

re: fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@mkdir obj/philo

$(OBJ_DIR)/%.o : src/%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : src/philo/%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo " -Making $(NAME)..."
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "		$(NAME) created"
	@echo "			-COMPILED-"

norm:
	@norminette -R CheckForbiddenHeader

.PHONY : all clean fclean re
