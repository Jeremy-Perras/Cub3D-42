/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:30:43 by jperras           #+#    #+#             */
/*   Updated: 2022/05/02 09:41:27 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_draw(t_data *data, int pix, int walltext)
{
  double y;

  (void) walltext;
  y =  0 / data->ray.perwalldist;
  while(y < (Width / 2) - (Width / 4) / data->ray.perwalldist)
  {
      mlx_put_image_to_window(data->mlx, data->win.ref, data->image[4].ref, pix , y);
      y += 4;
  }
  while(y < (Width / 2) + (Width / 4) / data->ray.perwalldist)
  {
      mlx_put_image_to_window(data->mlx, data->win.ref, data->image[2].ref, pix , y);
      y += 4;
  }
  while(y < Height)
  {
      mlx_put_image_to_window(data->mlx, data->win.ref, data->image[3].ref, pix , y);
      y += 4;
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
