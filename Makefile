# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 13:21:18 by jplevy            #+#    #+#              #
#    Updated: 2016/11/19 02:17:13 by jplevy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC_NAME = main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a
MLX_PATH = ./minilibx_macos/
MLX_NAME = libmlx.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@echo "Creating libft"
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@echo "Creating mlx"
	@$(MAKE) -C $(MLX_PATH) > /dev/null
	@echo "Creating Fractol"
	@$(CC) -o $(NAME) $(OBJ_NAME) -L. $(LIBFT_PATH)$(LIBFT_NAME) \
	$(MLX_PATH)$(MLX_NAME) -framework OpenGL -framework AppKit
	@echo "  Well done"

%.o: %.c
	@echo $@
	@$(CC) $(CFLAG) -o $@ -c $<
	@echo "  Well done"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean  > /dev/null
	@$(RM) $(OBJ_NAME)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all
