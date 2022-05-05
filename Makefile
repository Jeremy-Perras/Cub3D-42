# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <jperras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:57:03 by jperras           #+#    #+#              #
#    Updated: 2022/05/05 08:58:23 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = test.c windows.c hook.c raycasting.c parse.c parse_texture.c utils.c check_map.c floor_ceiling_color.c raycasting2.c put_colors.c image2.c teste2.c ft_split2.c
INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

CC = gcc

LIBMLX = -L minilibx -lmlx

FLAGS = -Wall -Werror -Wextra -g

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
