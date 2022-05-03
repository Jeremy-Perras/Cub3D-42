/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:30:43 by jperras           #+#    #+#             */
/*   Updated: 2022/05/03 14:34:25 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
void ft_draw_background(t_data *data)
{
  double y;
  double x;
  int color;

  x = 0;
  while (x < Width)
  {
    y = 0;
    while(y < Height / 2)
    {
	     color = create_trgb(0, data->c_r, data->c_g, data->c_b);
       		data->im = 20;
        my_mlx_pixel_put(data, x,  y, color);

        y ++;
    }
    while(y < Height)
  {
        color = create_trgb(0, data->f_r, data->f_g, data->f_b);
        		data->im = 20;
        my_mlx_pixel_put(data, x,  y, color);
        y ++ ;
      }
      x++;

    }
}

void ft_draw(t_data *data, int pix, int walltext)
{
  double y;
  int x;
  int end;
  (void) walltext;
  int color;


  x = pix;
  end = pix + 50;
  y =  0 / data->ray.perwalldist;
  y = (Width / 2) - (Width / 4) / data->ray.perwalldist ;
  while(y < (Width / 2) + (Width / 4) / data->ray.perwalldist)
  {
    color = (int)(data->image[walltext].image +
		data->image[walltext].line_length * (int)(50 - (int)pix % 50) +
		(int)(50 - (int)y % 50) * (data->image[walltext].bits_per_pixel / 8));
      // color = create_trgb(0, 0,255, 0);
        data->im = 20;
        my_mlx_pixel_put(data, x,  y, color);
      y ++;
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
