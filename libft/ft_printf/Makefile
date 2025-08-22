# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 00:41:56 by iokuno            #+#    #+#              #
#    Updated: 2025/05/15 06:46:39 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I.

AR		= ar rcs
RM		= rm -fr
SRCS	= ft_printf.c \
			printf_put_char.c \
			printf_put_fmt.c

OBJS	= $(SRCS:.c=.o)

$(NAME):$(OBJS)
	$(AR) $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean
