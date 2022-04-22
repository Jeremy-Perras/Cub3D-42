/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:03:23 by jperras           #+#    #+#             */
/*   Updated: 2022/04/22 13:50:09 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB_H
# define CUB_H
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vector
{
  int x;
  int y;
} t_vector;

typedef struct s_window
{
  void *ref;
  t_vector size;
} t_win;

typedef struct s_data
{
  void *mlx;
  t_win win;
}t_data;

/*
* ft_windows
*/
t_win	ft_windows(void *mlx, int widht, int height, char *title);

#endif
