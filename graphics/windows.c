/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:36:16 by jperras           #+#    #+#             */
/*   Updated: 2022/05/05 14:38:47 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_close(void)
{
	exit(0);
}

t_win	ft_windows(void *mlx, int width, int height, char *title)
{
	t_win	windows;

	(void) width;
	(void) height;
	windows.ref = mlx_new_window(mlx, WIDTH, HEIGHT, title);
	windows.size.x = WIDTH;
	windows.size.y = HEIGHT;
	mlx_hook(windows.ref, 17, 0, ft_close, 0);
	return (windows);
}

static t_image	ft_new_image(void *mlx, char *path)
{
	t_image	image;

	image.ref = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	return (image);
}

void	ft_put_add(t_data *data)
{
	data->image[5].addr = mlx_get_data_addr(data->image[5].ref,
			&(data->image[5].bits_per_pixel),
			&(data->image[5].line_length), &(data->image[5].endian));
	data->image[6].addr = mlx_get_data_addr(data->image[6].ref,
			&(data->image[6].bits_per_pixel),
			&(data->image[6].line_length), &(data->image[6].endian));
	data->image[7].addr = mlx_get_data_addr(data->image[7].ref,
			&(data->image[7].bits_per_pixel),
			&(data->image[7].line_length), &(data->image[7].endian));
	data->image[8].addr = mlx_get_data_addr(data->image[8].ref,
			&(data->image[8].bits_per_pixel),
			&(data->image[8].line_length), &(data->image[8].endian));
	data->image[20].image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image[20].addr = mlx_get_data_addr(data->image[20].image,
			&(data->image[20].bits_per_pixel),
			&(data->image[20].line_length), &(data->image[20].endian));
}

void	ft_put_image(t_data *data)
{
	data->image = malloc(sizeof(t_image) * 21);
	data->image[0] = ft_new_image(data->mlx, data->n);
	data->image[1] = ft_new_image(data->mlx, data->s);
	data->image[2] = ft_new_image(data->mlx, "image/Player.xpm");
	data->image[3] = ft_new_image(data->mlx, "image/White.xpm");
	data->image[4] = ft_new_image(data->mlx, "image/border2.xpm");
	data->image[5] = ft_new_image(data->mlx, data->n);
	data->image[6] = ft_new_image(data->mlx, data->s);
	data->image[7] = ft_new_image(data->mlx, data->e);
	data->image[8] = ft_new_image(data->mlx, data->w);
	data->image[9] = ft_new_image(data->mlx, "image/c.xpm");
	data->image[10] = ft_new_image(data->mlx, "image/f.xpm");
	data->image[19] = ft_new_image(data->mlx, "image/f.xpm");
	ft_put_add(data);
}
