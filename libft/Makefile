# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 21:25:54 by iokuno            #+#    #+#              #
#    Updated: 2025/07/16 12:21:25 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
RM          := rm -f
AR          := ar rcs

# Header files
INC         := libft.h
FT_PRINTF_INC := ft_printf/ft_printf.h

# ft_printf
FT_PRINTF_DIR := ft_printf
FT_PRINTF_SRCS := ft_printf.c printf_put_char.c printf_put_fmt.c
FT_PRINTF_OBJS := $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRCS:.c=.o))

# libft sources
SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS := $(SRCS:.c=.o)

# All object files
ALL_OBJS := $(OBJS) $(FT_PRINTF_OBJS)

all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(AR) $(NAME) $(ALL_OBJS)

# libft object files
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

# ft_printf object files
$(FT_PRINTF_DIR)/%.o: $(FT_PRINTF_DIR)/%.c $(FT_PRINTF_INC)
	$(CC) $(CFLAGS) -I $(FT_PRINTF_DIR) -c $< -o $@


clean:
	$(RM) $(OBJS) $(FT_PRINTF_OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re