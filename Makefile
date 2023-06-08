# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 11:38:02 by vipalaci          #+#    #+#              #
#    Updated: 2023/06/08 13:33:05 by vipalaci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOURS #
GREEN = \033[0;32m
COLOR_OFF = \033[0m

# VARIABLES #
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include -I ./libft/include
MLX = ./mlx/libmlx.a
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
DEBUG = -g3 -fsanitize=address
NAME = so_long
INCLUDE = include/

# OBJECTS #
SRC = main.c error.c

SRC_PATH = src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

# MLX_PATH = mlx/
# MLX = $(MLX_PATH)libmlx.a

# RULES #
all: $(NAME)

$(LIBFT): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)

# $(MLX) : $(MLX_PATH)
# 	@make -sC $(MLX_PATH)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(LIBFT)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)#### so_long has been created ####$(COLOR_OFF)"

clean:
	@make -C $(LIBFT_PATH) $(MLX_PATH) clean
	@$(RM) $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) $(MLX_PATH) fclean
	@$(RM) $(NAME) 
	@echo "$(GREEN)#### so_long cleaned successfuly ####$(COLOR_OFF)"

re: fclean all

.PHONY: all clean fclean re