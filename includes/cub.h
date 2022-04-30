/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:03:23 by jperras           #+#    #+#             */
/*   Updated: 2022/04/30 15:02:40 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB_H
# define CUB_H
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# define Height 1920
# define Width 1080
# define Screen 1920

typedef struct t_map
{
  char **map;
} t_map;

typedef struct s_vector
{
 int x;
 int y;
} t_vector;

 typedef struct s_position
{
  double x;
  double y;
} t_position;

typedef struct s_player
{
  t_position position;
  double speed;
  double angle;
  double rot_speed;
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
  t_image *image;
  t_map  map;
  t_player player;
} t_data;

/*
* windows.c
*/
t_win   ft_windows(void *mlx, int widht, int height, char *title);
void    ft_put_background(t_data *data);
void    ft_put_image(t_data *data);
/*
* hook.c
*/
int      key(int key, t_data *data);
void ft_raycasting(t_data *data);

#endif
