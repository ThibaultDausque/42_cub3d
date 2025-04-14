# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 11:03:14 by tdausque          #+#    #+#              #
#    Updated: 2024/10/24 15:49:58 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_calloc.c	\
		ft_substr.c	\
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_split.c

SRCS_BNS = ft_lstnew_bonus.c \
		   ft_lstadd_front_bonus.c \
		   ft_lstsize_bonus.c \
		   ft_lstlast_bonus.c \
		   ft_lstadd_back_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BNS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	
#  so: $(OBJS)
# 	gcc --shared $(OBJS) -o libft.so
	
bonus: $(OBJS_BNS)
	ar -rcs $(NAME) $(OBJS_BNS)

%.o: %.c
	@$(CC) -o $@ $(CFLAGS) -c $^
	@echo "\033[32mCopiling $^ to $@!\033[0m"

clean :
	$(RM) $(OBJS) $(OBJS_BNS)

fclean :	clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
