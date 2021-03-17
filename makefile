# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 11:10:49 by user42            #+#    #+#              #
#    Updated: 2021/03/17 17:27:29 by alboumed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I./include

NAME = minishell.a

LIBFTD = ./Libft/libft.a

MINILIBX = -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRC_PATH =	get_next_line.c			\
			get_next_line_utils.c	\
			main.c					\

SRC = $(addprefix src/,$(SRC_PATH))

OBJ	= $(SRC:.c=.o)

all : libft $(NAME)

clean :
	$(RM) $(OBJ)
	make clean -C Libft

fclean : clean
	$(RM) $(NAME) a.out
	make fclean -C Libft

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) -o minish src/main.c $(NAME) $(LIBFTD)

libft :
	make all -C Libft

re : fclean all

.PHONY : all libft clean re