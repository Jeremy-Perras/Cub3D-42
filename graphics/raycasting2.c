/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:30:43 by jperras           #+#    #+#             */
/*   Updated: 2022/05/06 10:24:30 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_background(t_data *data)
{
	double			y;
	double			x;
	unsigned int	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y <= HEIGHT / 2)
		{
			color = create_trgb(0, data->c_r, data->c_g, data->c_b);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		while (y <= HEIGHT)
		{
			color = create_trgb(0, data->f_r, data->f_g, data->f_b);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_draw(t_data *data, int pix, int walltext)
{
	double			y;
	unsigned int	color;
	char			*dst;

	y = (HEIGHT / 2) - (HEIGHT / 4) / data->ray.perwalldist ;
	if (y >= 0 && y <= HEIGHT)
	{
		while (y <= (HEIGHT / 2) + (HEIGHT / 4) / data->ray.perwalldist)
		{
			dst = (data->image[walltext].addr)
				+ (int)(data->image[walltext].line_length
					* floor((data->image[walltext].size.y
							* ((y - ((HEIGHT / 2)
										- (HEIGHT / 4) / data->ray.perwalldist))
								/ (((HEIGHT / 2)
										+ (HEIGHT / 4) / data->ray.perwalldist)
									- ((HEIGHT / 2) - (HEIGHT / 4)
										/ data->ray.perwalldist)))))
					+ (pix % data->image[walltext].size.x)
					* (data->image[walltext].bits_per_pixel / 8));
			color = *(unsigned int *) dst;
			my_mlx_pixel_put(data, pix, y, color);
		y++;
		}
	}
}

void	ft_distwall(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perwalldist = ((float)data->ray.mapx - data->player.position.x
				+ (1 - data->ray.stepx) / 2) / data->ray.dirx;
	else
		data->ray.perwalldist = ((float)data->ray.mapy - data->player.position.y
				+ (1 - data->ray.stepy) / 2) / data->ray.diry;
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
