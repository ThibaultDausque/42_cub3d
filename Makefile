# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:32:53 by tdausque          #+#    #+#              #
#    Updated: 2025/04/17 10:49:22 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

MAIN_SRC = src/main.c

PARSE_SRC = src/parsing/parse.c \
		src/parsing/extension.c \
		src/parsing/flood_fill.c

UTILS_SRC = src/utils/utils.c

RAYCAST_SRC = 	src/raycasting/create.c \
				src/raycasting/free.c \
				src/raycasting/raycasting.c

SRCS = $(PARSE_SRC) $(UTILS_SRC) $(MAIN_SRC) $(RAYCAST_SRC)
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes -Ib_libft/includes
LIB = b_libft/big_lib.a
RM = rm -f

BAR_LENGTH := 50
TOTAL_FILES := $(words $(SRCS))
COMPILED_FILES := 0
NAME = cub3D

define progress_bar
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	$(eval PROGRESS_PERCENT=$(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	$(eval FILLED_BAR_LENGTH=$(shell echo $$(($(PROGRESS_PERCENT) * $(BAR_LENGTH) / 100))))
	@printf "\rCompiling [\033[0;36m"
	@for i in $(shell seq 1 $(FILLED_BAR_LENGTH)); do printf "#"; done
	@for i in $(shell seq 1 $(shell echo $$(($(BAR_LENGTH) - $(FILLED_BAR_LENGTH))))); do printf " "; done
	@printf "\033[0m] $(PROGRESS_PERCENT)%%"
endef

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -Lmlx_linux -lmlx -lXext -lX11 -lm -o $(NAME) $(LIB)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(call progress_bar)
	@cd b_libft && make -s
	@cd mlx_linux && make -s
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@rm -rf $(OBJS_DIR)
	@$(RM) $(OBJS) $(OBJS_BNS)

fclean :	clean
	@rm -f $(NAME)
	@cd b_libft && make fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
