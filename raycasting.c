/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:49:10 by jperras           #+#    #+#             */
/*   Updated: 2022/04/26 18:12:23 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"


void ft_raycasting(t_data *data)
{
  int pix;
  int ratio;
  double dirx;
  double diry;
  int mapx;
  int mapy;
  double deltadistx;
  double deltadisty;
  int stepx;
  int stepy;
  double sidedistx;
  double sidedisty;
  int hit;
  double perwalldist;
  int side;

  pix = 0;
  hit = 0;
  while(pix < Screen)
  {
    ratio = (pix - (Screen / 2)) / (Screen /2);
    dirx = cos(data->player.angle) / 2 + cos(data->player.angle - 0.25) * ratio+0.1;
    diry = sin(data->player.angle) / 2 + sin(data->player.angle - 0.25) * ratio+0.1;
    mapx = floor(data->player.position.x);
    mapy = floor(data->player.position.y);
    deltadistx = sqrt(1+(diry *diry)/(dirx * dirx));
    deltadisty = sqrt(1+(dirx *dirx)/(diry * diry));
    if(dirx < 0)
    {
      stepx = -1;
      sidedistx = (data->player.position.x - mapx) * deltadistx;
    }
    else
    {
      stepx = 1;
      sidedistx = (mapx + 1 - data->player.position.x ) * deltadistx;
    }
    if(diry < 0)
    {
      sidedisty = (data->player.position.y - mapy) * deltadisty;
      stepy = -1;
    }
    else
    {
      stepy = 1;
      sidedisty = (mapy + 1 - data->player.position.y ) * deltadisty;
    }
    while(hit == 0)
    {
      if(sidedistx < sidedisty)
      {
        sidedistx += deltadistx;
        mapx = stepx;
        side = 0;
      }
      else
      {
        sidedisty += deltadisty;
        mapy = stepy;
        side = 1;
      }
      if(data->map.map[mapy][mapx] != '0')
        hit = 1;
    }
    if (side == 0)
      perwalldist = (mapx - data->player.position.x +(1 - stepx) / 2) / dirx;
    else
        perwalldist = (mapy - data->player.position.y +(1 - stepy) / 2) / diry;
    double y = 64 - 32 / perwalldist;
    while(y < 64 + (32 / perwalldist))
    {
        mlx_pixel_put(data->mlx, data->win.ref, pix, y, 0xFF0000);
        y++;
    }
    pix++;
  }
}
