/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:36:16 by jperras           #+#    #+#             */
/*   Updated: 2022/04/23 14:23:15 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_close(void)
{
	exit(0);
}

t_win	ft_windows(void *mlx, int widht, int height, char *title)
{
	t_win	windows;

	windows.ref = mlx_new_window(mlx, widht, height, title);
	windows.size.x = widht;
	windows.size.y = height;
	mlx_hook(windows.ref, 17, 0, ft_close, 0);
	return (windows);
}

t_image	ft_new_image(void *mlx, char *path)
{
	t_image	image;

	image.ref = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	return (image);
}

void ft_put_image(t_data *data)
{
	data.image = malloc(sizeof(t_image) * 2);

}

void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y * Height < data->win.size.y)
	{
		x = 0;
		while (x * Width < data->win.size.x)
		{
			if (data->map.map[x][y] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[0].ref, Width * x, Height* y);
			}
			else
				mlx_put_image_to_window(data->mlx, data->win.ref,
					data->image[0].ref, Width * x, Height* y);
			x++;
		}
		y++;
	}
}
