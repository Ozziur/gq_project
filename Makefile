# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 17:53:51 by mruizzo           #+#    #+#              #
#    Updated: 2022/05/06 17:57:22 by mruizzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
INCLUDE = -framework OpenGL -framework AppKit -lmlx

NAME = gq_project
SRC = main.c

MLX_A = libmlx.a
MLX_DIR = mlx/
MLX = $(addprefix $(MLX_DIR), $(MLX_A))


OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	make -C $(MLX_DIR)
	$(CC) $(INCLUDE) $(OBJ) $(MLX) -o $(NAME)

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re bonus play