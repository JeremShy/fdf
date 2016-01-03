# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:49:18 by jcamhi            #+#    #+#              #
#    Updated: 2015/12/18 16:31:21 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c \
		   parsing.c \
		   get_next_line.c \
		   matrice.c \
		   draw_line.c \
		   algobern.c \
		   event.c \
		   handle_error.c

OBJ_PATH = ./obj/

INC_PATH = ./includes

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -Llib/ -lft -lmlx

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME) :
#	mkdir lib/
#	make -C minilibx
#	make -C libft
	$(CC) $(LFLAGS) $(INC) -o $(NAME) $(SRC_NAME) -framework OpenGL -framework AppKit

clean:
#		make -C libft clean
#		make -C minilibx clean
	    rm -fv $(OBJ)
	
fclean: clean
	rm -fv $(NAME)
#	rm -rf lib/
#	make -C libft fclean
#	make -C minilibx fclean

re: fclean all

.PHONY : all clean fclean re
