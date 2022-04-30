/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:02:29 by jperras           #+#    #+#             */
/*   Updated: 2022/04/30 17:30:01 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_init(t_data *data)
{
  data->map1.map = data->map;
  data->player.position.x = 4;
  data->player.position.y = 4;
  data->player.speed = 1.0;
  data->player.angle = 0;
  data->player.rot_speed = M_PI / 2;
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
  ft_draw(data);
  ft_put_background(data);
  ft_raycasting(data);
  mlx_key_hook(data->win.ref, key, data);

  mlx_loop(data->mlx);
}
