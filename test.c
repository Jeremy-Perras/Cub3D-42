/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:02:29 by jperras           #+#    #+#             */
/*   Updated: 2022/04/25 16:47:44 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_init(t_data *data)
{
  data->map.map = malloc(sizeof(char *) *8);
  data->map.map[0] = malloc(sizeof(char) *8);
  data->map.map[1] = malloc(sizeof(char) *8);
  data->map.map[2] = malloc(sizeof(char) *8);
  data->map.map[3] = malloc(sizeof(char) *8);
  data->map.map[4] = malloc(sizeof(char) *8);
  data->map.map[5] = malloc(sizeof(char) *8);
  data->map.map[6] = malloc(sizeof(char) *8);
  data->map.map[7] = malloc(sizeof(char) *8);

  data->map.map[0] = "11111111";
  data->map.map[1] = "10000001";
  data->map.map[2] = "10000001";
  data->map.map[3] = "10000001";
  data->map.map[4] = "10000001";
  data->map.map[5] = "10000001";
  data->map.map[6] = "10000001";
  data->map.map[7] = "11111111";
  data->player.position.x = 4;
  data->player.position.y = 4;
  data->player.speed = 1.0;
  data->player.angle = 0;
  data->player.rot_speed = M_PI / 2;
}

int main(void)
{
  t_data  data;

  data.mlx = mlx_init();
  data.win = ft_windows(data.mlx, 50 * 8, 50 * 8, "test");
  ft_init(&data);
  ft_put_image(&data);
  mlx_key_hook(data.win.ref, key, &data);
  ft_put_background(&data);
  mlx_loop(data.mlx);
}
