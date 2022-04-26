/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:49:10 by jperras           #+#    #+#             */
/*   Updated: 2022/04/26 16:23:11 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"


void ft_raycsting(t_data *data)
{
  int pix;
  int ratio;
  double dirx;
  double diry;
  int mapx;
  int mapy;
  double deltadistx;
  double deltaisty;
  int stepx;
  int stepy;
  double sidedistx;
  double sidedisty;
  int hit;
  double perwalldist;

  pix = 0;
  hi = 0;
  while(pix < Screen)
  {
      ratio = (pix - (Screen / 2)) / (Screen /2);
      dirx = cos(data->player.angle) / 2 + cos(data->player.angle - 0.25) * ratio;
      diry = sin(data->player.angle) / 2 + sin(data->player.angle - 0.25) * ratio;
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
        if(data->map[mapy][mapx] != '0')
          hit = 1;
      }
      if (side == 0)
      {
        perwalldist = (mapx - data->player.x +(1 - stepx) / 2) / dirx;


      }
    pix++;
  }







}
