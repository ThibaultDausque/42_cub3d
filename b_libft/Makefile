# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 11:03:14 by tdausque          #+#    #+#              #
#    Updated: 2025/04/17 10:29:37 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = big_lib.a
CC = cc

PRINTF_SRCS = ft_printf/ft_print_char.c \
			ft_printf/ft_print_hex.c \
			ft_printf/ft_print_nbr.c \
			ft_printf/ft_print_str.c \
			ft_printf/ft_print_ptr.c \
			ft_printf/ft_print_unbr.c \
			ft_printf/ft_printf.c

GNL_SRCS = get_next_line/get_next_line.c \
		   get_next_line/get_next_line_utils.c

LIBFT_SRCS =	libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_calloc.c	\
		libft/ft_substr.c	\
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_itoa.c \
		libft/ft_split.c

SRCS_BNS = libft/ft_lstnew_bonus.c \
		   libft/ft_lstadd_front_bonus.c \
		   libft/ft_lstsize_bonus.c \
		   libft/ft_lstlast_bonus.c \
		   libft/ft_lstadd_back_bonus.c

INCLUDES = -Iincludes
SRCS = $(PRINTF_SRCS) $(GNL_SRCS) $(LIBFT_SRCS) $(SRCS_BNS)
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

BAR_LENGTH := 50
TOTAL_FILES := $(words $(SRCS))
COMPILED_FILES := 0

define progress_bar
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	$(eval PROGRESS_PERCENT=$(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	$(eval FILLED_BAR_LENGTH=$(shell echo $$(($(PROGRESS_PERCENT) * $(BAR_LENGTH) / 100))))
	@printf "\rCompiling [\033[0;35m"
	@for i in $(shell seq 1 $(FILLED_BAR_LENGTH)); do printf "#"; done
	@for i in $(shell seq 1 $(shell echo $$(($(BAR_LENGTH) - $(FILLED_BAR_LENGTH))))); do printf " "; done
	@printf "\033[0m] $(PROGRESS_PERCENT)%%"
endef

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(call progress_bar)
	@$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $^

clean :
	@rm -rf $(OBJS_DIR)
	@$(RM) $(OBJS) $(OBJS_BNS)

fclean :	clean
	@rm -f $(NAME)
	@$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
