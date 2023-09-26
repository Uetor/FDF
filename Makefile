# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 18:30:08 by pedrogon          #+#    #+#              #
#    Updated: 2023/09/26 20:10:45 by pedrogon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = example.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT_PATH = ./libft
MLX42_PATH = ./MLX42
GLFW_FLAGS = -lglfw -L /Users/pedrogon/.brew/opt/glfw/lib/ -lm
MLX42_A = ./MLX42/libmlx42.a
LIBFT_A = ./libft/libft.a 
INCLUDE = -I ./libft -I ./MLX42/include
OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	make -C $(MLX42_PATH)
	make -C $(LIBFT_PATH)	
	$(CC) $(CFLAGS) $(SRC) $(OBJS) $(GLFW_FLAGS) $(LIBFT_A) $(MLX42_A) $(INCLUDE) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all : $(NAME)

clean :
	make -C $(LIBFT_PATH) clean
	make -C $(MLX42_PATH) clean
	$(RM) $(NAME)
fclean : clean
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX42_PATH) fclean
	$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re
