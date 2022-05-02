/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:36:16 by jperras           #+#    #+#             */
/*   Updated: 2022/05/02 12:10:01 by jperras          ###   ########.fr       */
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

static t_image	ft_new_image(void *mlx, char *path)
{
	t_image	image;

	image.ref = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	return (image);
}

void ft_put_image(t_data *data)
{
	data->image = malloc(sizeof(t_image) * 11);
	data->image[0] = ft_new_image(data->mlx, data->n);
	data->image[1] = ft_new_image(data->mlx, data->s);
	data->image[2] = ft_new_image(data->mlx, "image/Player.xpm");
	data->image[3] = ft_new_image(data->mlx, "image/White.xpm");
	data->image[4] = ft_new_image(data->mlx, "image/Red.xpm");
	data->image[5] = ft_new_image(data->mlx, data->n);
	data->image[6] = ft_new_image(data->mlx, data->s);
	data->image[7] = ft_new_image(data->mlx, data->e);
	data->image[8] = ft_new_image(data->mlx, data->w);
	data->image[9] = ft_new_image(data->mlx, "image/c.xpm");
	data->image[10] = ft_new_image(data->mlx, "image/f.xpm");
}

void	ft_put_background_init(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				    mlx_put_image_to_window(data->mlx, data->win.ref, data->image[4].ref, x * 4, y * 4);
			else if (data->map[y][x] == '0')
				    mlx_put_image_to_window(data->mlx, data->win.ref, data->image[3].ref, x * 4, y * 4);
			if(data->map[y][x] == 'N' || data->map[y][x] == 'S'||data->map[y][x] == 'E'|| data->map[y][x] == 'O')
			{
				data->player.position.x = x;
			  data->player.position.y = y;
				mlx_put_image_to_window(data->mlx, data->win.ref, data->image[2].ref, x * 4, y * 4);
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
	x = 0;

	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
			{
				    mlx_put_image_to_window(data->mlx, data->win.ref, data->image[4].ref, x * 4, y * 4);
			}
			else if (data->map[y][x] == '0')
				    mlx_put_image_to_window(data->mlx, data->win.ref, data->image[3].ref, x * 4, y * 4);
			if((int)round(data->player.position.x) == x && (int)round(data->player.position.y) == y)
				 mlx_put_image_to_window(data->mlx, data->win.ref, data->image[2].ref, x *4, y * 4);
			x++;
		}
		y++;
	}
}
