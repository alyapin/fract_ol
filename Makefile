# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzina <kzina@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 16:32:52 by kzina             #+#    #+#              #
#    Updated: 2019/08/12 20:50:03 by kzina            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fract_ol

HEADER = ./includes/fract_ol.h

SRC =   main.c\
		init_mlx.c\
		mandelbrot.c\
		math.c\
		render.c\

OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 

MLX = ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx_macos
MLX_LNK	= -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./sources/
INCDIR	= ./includes/
OBJDIR	= ./obj/

GREEN= \033[0;32m
RED= \033[0;031m
RESET= \033[0m

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c $(HEADER)
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "\n$(NAME): $(GREEN) object files were created $(RESET)"
	@echo "$(NAME): $(GREEN) $(NAME) was created $(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: clean fclean all re