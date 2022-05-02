/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:02:29 by jperras           #+#    #+#             */
/*   Updated: 2022/05/02 16:04:52 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void ft_init(t_data *data)
{
  data->map1.map = data->map;
  data->player.speed = 1;
  if(data->player_orientation == 'N')
  {
   data->player.angle = M_PI / 2;
  }
  if(data->player_orientation == 'S')
  {
   data->player.angle = - M_PI / 2;
  }
  if(data->player_orientation == 'E')
	{
     data->player.angle = 0;
  }
  if(data->player_orientation == 'O')
  {
     data->player.angle = M_PI;
  }
  data->player.angle = 0;
  data->player.rot_speed = (30 * M_PI) / 180;
  data->ray.colorfloor = create_trgb(0,  data->f_r, data->f_g,  data->f_b);
  data->ray.colorcelling =  create_trgb(0,  data->c_r, data->c_g,  data->c_b);
}

int main(int ac, char **av)
{
  t_data *data;

  if (ac != 2)
    return (printf("Error\nInsufficient number of arguments"));
  if (!(ft_strrchr(av[1], '.')) || ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 4) != 0)
    return (printf("Error\n Invalid map extension\n"));
  data = ft_parse_map(av[1]);
  printf("%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", data->n, data->s, data->e, data->w, data->c_r, data->c_g, data->c_b, data->f_r, data->f_g, data->f_b);
  int i = -1;
  while (data->map[++i])
    printf("%s\n", data->map[i]);
  data->mlx = mlx_init();
  data->win = ft_windows(data->mlx, Width ,Height , "test");
  ft_init(data);
  ft_put_image(data);
  ft_image2(data);
  ft_put_background_init(data);
  ft_raycasting(data);
  mlx_key_hook(data->win.ref, key, data);
  mlx_loop(data->mlx);
}
