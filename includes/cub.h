/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:03:23 by jperras           #+#    #+#             */
/*   Updated: 2022/04/23 14:23:14 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB_H
# define CUB_H
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# define Height 50
# define Width 50

typedef struct t_map
{
  char **map;
} t_map;

 struct s_vector
{
  int x;
  int y;
} t_vector;

typedef struct s_player
{
  t_vector position;
} t_player;

typedef struct s_image
{
  void * ref;
  t_vector size;
} t_image;

typedef struct s_window
{
  void *ref;
  t_vector size;
} t_win;

typedef struct s_data
{
  void *mlx;
  t_win win;
  t_image image;
  t_data  map;
} t_data;

/*
* windows.c
*/
t_win   ft_windows(void *mlx, int widht, int height, char *title);
t_image ft_new_image(void *mlx, char *path);
/*
* hook.c
*/
int      key(int key, t_data *data);
#endif
