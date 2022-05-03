/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:58:03 by jperras           #+#    #+#             */
/*   Updated: 2022/05/03 16:59:35 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
void ft_move_player(t_data *data, double pos)
{
  double tmpx;
  double tmpy;

  tmpx = data->player.position.x + (data->player.speed * cos(data->player.angle)) * pos;
  if (data->map1.map[(int)round(data->player.position.y)][(int)round(tmpx)] == '0')
    data->player.position.x = tmpx;
  tmpy = data->player.position.y + (data->player.speed * sin(data->player.angle)) * pos;
  if (data->map1.map[(int)round(tmpy)][(int)round(data->player.position.x)] == '0')
    data->player.position.y = tmpy;
}

int key(int key, t_data *data)
{
  (void) data;
  if (key == 13)
    ft_move_player(data, 1.0);
  if (key == 1)
    ft_move_player(data, -1.0);
  if (key == 0)
    data->player.angle += data->player.rot_speed;
  if (key == 2)
    data->player.angle -= data->player.rot_speed;
  if (data->player.angle >= 2 * M_PI)
    data->player.angle -= 2 * M_PI;
  if (data->player.angle <= - 2 * M_PI)
    data->player.angle += 2 * M_PI;
  ft_raycasting(data);
  ft_put_background(data);
    return (0);
}
