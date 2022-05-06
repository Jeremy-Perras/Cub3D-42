/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:02:29 by jperras           #+#    #+#             */
/*   Updated: 2022/05/06 10:12:48 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_init(t_data *data)
{
	data->map1.map = data->map;
	data->player.speed = 0.4;
	if (data->player_orientation == 'N')
		data->player.angle = 0;
	if (data->player_orientation == 'S')
		data->player.angle = -M_PI;
	if (data->player_orientation == 'E')
		data->player.angle = M_PI / 2;
	if (data->player_orientation == 'W')
		data->player.angle = -M_PI / 2;
	data->player.rot_speed = (10 * M_PI) / 180;
	data->ray.colorfloor = create_trgb(0, data->f_r, data->f_g, data->f_b);
	data->ray.colorcelling = create_trgb(0, data->c_r, data->c_g, data->c_b);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		exit_error("Error\nInsufficient number of arguments");
	if (!(ft_strrchr(av[1], '.')) || ft_strncmp((ft_strrchr(av[1], '.')),
			".cub", 4) != 0)
		exit_error("Error\nInvalid map extension");
	data = ft_parse_map(av[1]);
	data->mlx = mlx_init();
	data->win = ft_windows(data->mlx, WIDTH, HEIGHT, "test");
	ft_init(data);
	ft_put_image(data);
	ft_put_background_init(data);
	ft_raycasting(data);
	ft_put_background_init(data);
	mlx_do_sync(data->mlx);
	mlx_hook(data->win.ref, 2, 1l << 0, key, data);
	mlx_loop(data->mlx);
}
