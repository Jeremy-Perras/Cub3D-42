/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:30:43 by jperras           #+#    #+#             */
/*   Updated: 2022/05/02 10:46:35 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_draw(t_data *data, int pix, int walltext)
{
  double y;
  int x;
  int end;


  x = pix;
  end = pix + 50;
  y =  0 / data->ray.perwalldist;
  while(y < (Width / 2) - (Width / 4) / data->ray.perwalldist)
  {
    while(x < end)
    {
      mlx_pixel_put(data->mlx, data->win.ref,  x, y, data->ray.colorcelling);
      x++;
    }
      x = pix;
      y += 1;
  }
  while(y < (Width / 2) + (Width / 4) / data->ray.perwalldist)
  {
      mlx_put_image_to_window(data->mlx, data->win.ref, data->image[walltext].ref, pix , y);
      y += 20;
  }
  while(y < Height)
  {
    while(x < end)
    {
      mlx_pixel_put(data->mlx, data->win.ref,  x, y, data->ray.colorfloor);
      x++;
    }
      x = pix;
      y += 1;
  }
}

void ft_distwall(t_data *data)
{
  if (data->ray.side == 0)
    data->ray.perwalldist = ((float)data->ray.mapx - data->player.position.x
    + (1 - data->ray.stepx) / 2) / data->ray.dirx;
  else
      data->ray.perwalldist = ((float)data->ray.mapy - data->player.position.y
      + (1 - data->ray.stepy) / 2) / data->ray.diry;
}

int	create_trgb(int t, int r, int g, int b)
{
  return (t << 24 | r << 16 | g << 8 | b);
}
