# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 12:43:07 by iokuno            #+#    #+#              #
#    Updated: 2025/07/13 01:26:16 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Ofast -ffast-math \
		-I inc -I libft -I libft/ft_printf -I minilibx-linux

LFLAGS  = -L minilibx-linux -lmlx -lXext -lX11 -lm -L libft -lft

RM      = rm -f

SRCDIR  = src
OBJDIR  = obj
SRCFILE = main.c mandelbrot.c julia.c error.c \
		utility00.c utility01.c zoom.c arg_check.c
SRCS    = $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS    = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(MLX_LIB):
	test -d $(MLX_DIR) || git clone $(MLX_REPO)
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

check:
	cc -fsanitize=address -g $(SRCS)

.PHONY: all clean fclean re