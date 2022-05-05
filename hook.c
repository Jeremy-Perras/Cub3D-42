/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:05 by jperras           #+#    #+#             */
/*   Updated: 2022/05/05 10:20:06 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub.h"
void ft_move_player(t_data *data, double pos)
{
  double tmpx;
  double tmpy;
  // int tmpx2;
  // int tmpy2;

  tmpx = data->player.position.x + (data->player.speed * cos(data->player.angle)) * pos;
  if (data->map1.map[(int)floor(data->player.position.y)][(int)floor(tmpx)] != '1')
    data->player.position.x = tmpx;
  tmpy = data->player.position.y + (data->player.speed * sin(data->player.angle)) * pos;
  if (data->map1.map[(int)floor(tmpy)][(int)floor(data->player.position.x)] != '1')
    data->player.position.y = tmpy;
}

void ft_left_right(t_data * data, int key)
{
  double tmpx;
  double tmpy;

  tmpx = data->player.position.x;
  tmpy = data->player.position.y;
  if(( data->player.angle <= (45 * M_PI) / 180 || data->player.angle > (315 * M_PI) / 180) && key == 0)
  {
    tmpy+=data->player.speed;
    if (data->map1.map[(int)round(tmpy)][(int)round(data->player.position.x)] == '0')
      data->player.position.y = tmpy;
  }
  else if (data->player.angle <= (45 * M_PI) / 180 || data->player.angle > (315 * M_PI) / 180)
  {
    tmpy-=data->player.speed;
    if (data->map1.map[(int)round(tmpy)][(int)round(data->player.position.x)] == '0')
      data->player.position.y = tmpy;

  }
  if(( data->player.angle > (45 * M_PI) / 180 && data->player.angle <= (135 * M_PI) / 180) && key == 0)
  {
    tmpx-= data->player.speed;
    if (data->map1.map[(int)round(data->player.position.y)][(int)round(tmpx)] == '0')
      data->player.position.x = tmpx;
  }
  else if ( data->player.angle> (45 * M_PI) / 180 && data->player.angle <= (135 * M_PI) / 180)
  {
    tmpx+=data->player.speed;
    if (data->map1.map[(int)round(data->player.position.y)][(int)round(tmpx)] == '0')
      data->player.position.x = tmpx;

  }
  if(( data->player.angle > (135 * M_PI) / 180 && data->player.angle <= (225 * M_PI) / 180) && key == 0)
  {
    tmpy-=data->player.speed;
    if (data->map1.map[(int)round(tmpy)][(int)round(data->player.position.x)] == '0')
      data->player.position.y = tmpy;
  }
  else if ( data->player.angle > (135 * M_PI) / 180  && data->player.angle <= (225 * M_PI) / 180)
  {
    tmpy+=data->player.speed;
    if (data->map1.map[(int)round(tmpy)][(int)round(data->player.position.x)] == '0')
      data->player.position.y = tmpy;

  }
  if((  data->player.angle > (225 * M_PI) / 180 && data->player.angle <= (315 * M_PI) / 180) && key == 0)
  {
    tmpx+=data->player.speed;
    if (data->map1.map[(int)round(data->player.position.y)][(int)round(tmpx)] == '0')
      data->player.position.x = tmpx;
  }
  else if ( data->player.angle > (225 * M_PI) / 180 && data->player.angle <= (315 * M_PI) / 180)
  {
    tmpx-=data->player.speed;
    if (data->map1.map[(int)round(data->player.position.y)][(int)round(tmpx)] == '0')
      data->player.position.x = tmpx;

  }
}


int key(int key, t_data *data)
{
  (void) data;
  if (key == 13)
    ft_move_player(data, 1.0);
  if (key == 1)
    ft_move_player(data, -1.0);
  if (key == 0 || key == 2)
    ft_left_right(data, key);
  if (key == 123)
    data->player.angle += data->player.rot_speed;
  if (key == 124)
    data->player.angle -= data->player.rot_speed;
  if (data->player.angle >= 2 * M_PI)
    data->player.angle -= 2 * M_PI;
  if (data->player.angle <= 0)
    data->player.angle = 2 * M_PI + data->player.angle;
  ft_raycasting(data);
  ft_put_background(data);
    return (0);
}
