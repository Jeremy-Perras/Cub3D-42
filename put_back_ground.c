/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back_ground.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:57:53 by jperras           #+#    #+#             */
/*   Updated: 2022/05/05 12:58:24 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

void	ft_put_background_init(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map2[y])
	{
		x = 0;
		while (data->map2[y][x])
		{
			if (data->map2[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[4].ref, x * 4, y * 4);
			else if (data->map2[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[3].ref, x * 4, y * 4);
			if (data->player.position.x == x && data->player.position.y == y)
			{
				data->map2[y][x] = '0';
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[2].ref, x * 4, y * 4);
			}
			x++;
		}
		y++;
	}
}

void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map2[y])
	{
		x = 0;
		while (data->map2[y][x])
		{
			if (data->map2[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[4].ref, x * 4, y * 4);
			else if (data->map2[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[3].ref, x * 4, y * 4);
			if ((int)round(data->player.position.x) == x
				&& (int)round(data->player.position.y) == y)
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[2].ref, x * 4, y * 4);
			x++;
		}
		y++;
	}
}
