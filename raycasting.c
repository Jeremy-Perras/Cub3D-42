/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:49:10 by jperras           #+#    #+#             */
/*   Updated: 2022/05/03 17:02:00 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"
static int  ft_choose_wall(int side, int dirx, int diry)
{
  int walltext;

  if (side ==0)
  {
      if (dirx > 0)
        walltext = 5;
      else
        walltext = 6;
  }
  else
  {
    if (diry > 0)
      walltext = 7;
    else
      walltext = 8;
  }
  return(walltext);
}

static void ft_init(t_data *data, int pix)
{
  data->ray.camx = ((double)pix - (Width / 2)) / (Width / 2);
  data->ray.dirx = cos(data->player.angle) / 2 + cos(data->player.angle - (M_PI * 75) / 180) *   data->ray.camx;
  data->ray.diry = sin(data->player.angle) / 2  + sin(data->player.angle - (M_PI * 75) / 180) *   data->ray.camx;
  data->ray.mapx = floor(data->player.position.x);
  data->ray.mapy = floor(data->player.position.y);
  data->ray.deltadistx = sqrt(1 + (data->ray.diry * data->ray.diry) / (data->ray.dirx  * data->ray.dirx));
  data->ray.deltadisty = sqrt(1 + (data->ray.dirx  * data->ray.dirx ) / (data->ray.diry * data->ray.diry));
}
static void ft_distinit(t_data *data)
{
  if(data->ray.dirx < 0)
  {
    data->ray.stepx = -1;
    data->ray.sidedistx = (data->player.position.x - (double) data->ray.mapx) *   data->ray.deltadistx;
  }
  else
  {
    data->ray.stepx = 1;
    data->ray.sidedistx = ((double)data->ray.mapx + 1 - data->player.position.x) *   data->ray.deltadistx;
  }
  if(data->ray.diry < 0)
  {
    data->ray.stepy = -1;
    data->ray.sidedisty = (data->player.position.y - (double) data->ray.mapy) * data->ray.deltadisty;
  }
  else
  {
    data->ray.stepy = 1;
    data->ray.sidedisty = ((double)data->ray.mapy + 1 - data->player.position.y ) * data->ray.deltadisty;
  }
}

void ft_wall(t_data *data)
{
  if((data->ray.sidedistx >= 0 || data->ray.sidedisty <= 0) && data->ray.sidedistx < data->ray.sidedisty)
  {
    data->ray.sidedistx += data->ray.deltadistx;
    data->ray.mapx +=   data->ray.stepx;
    data->ray.side = 0;
  }
  else
  {
    data->ray.sidedisty += data->ray.deltadisty;
    data->ray.mapy += data->ray.stepy;
    data->ray.side = 1;
  }
}

void ft_raycasting(t_data *data)
{
  int walltext;
  int pix;
  double hit;

  data->ray.camx = 0;
  pix = 0;

  mlx_clear_window(data->mlx, data->win.ref);
  ft_draw_background(data);
  while(pix < Width)
  {
    hit = 0;
    ft_init(data, pix);
    ft_distinit(data);
    while(hit == 0)
    {
      ft_wall(data);
      if(data->map1.map[data->ray.mapy][data->ray.mapx] != '0')
        hit = 1;
    }
    walltext = ft_choose_wall(data->ray.side, data->ray.dirx, data->ray.diry);
    ft_distwall(data);
    ft_draw(data ,pix, walltext);
    pix++;
  }
  mlx_put_image_to_window(data->mlx, data->win.ref, data->image[20].image, 0, 0);
}
