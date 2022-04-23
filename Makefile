# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <jperras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:57:03 by jperras           #+#    #+#              #
#    Updated: 2022/04/23 21:26:30 by jeremyperras     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = test.c windows.c hook.c

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

CC = gcc

LIBMLX = -L minilibx -lmlx

FLAGS = -Wall -Werror -Wextra

#LIBMLX = -L /usr/local/lib -lmlx

LIBFT = -L libft -lft

LIBPF = -L printf -lftprintf

OTHER = -framework OpenGL -framework AppKit

.c.o:
		${CC} ${FLAGS} -I./includes  -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make -C libft
	make -C minilibx
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(LIBFT) $(OTHER) $(INCLUDES) $(OBJS)

all : $(NAME)


test :
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(LIBFT) $(INCLUDES) $(OTHER) $(SRCS)

debug :
	$(CC) -g $(FLAGS) -o $(NAME) $(LIBMLX) $(LIBFT) $(INCLUDES) $(OTHER) $(SRCS)

clean :
	make clean -C libft
	make clean -C minilibx
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft
	make fclean -C minilibx
	rm -rf $(NAME)

re : fclean all
	make re -C libft
	make re -C minilibx
