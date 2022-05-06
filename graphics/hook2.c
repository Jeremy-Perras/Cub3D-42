/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:27:24 by jperras           #+#    #+#             */
/*   Updated: 2022/05/06 09:35:42 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_left_right4(t_data *data, int key)
{
	double	tmpx;
	double	tmpy;

	tmpx = data->player.position.x;
	tmpy = data->player.position.y;
	if ((data->player.angle > (225 * M_PI) / 180
			&& data->player.angle <= (315 * M_PI) / 180) && key == 0)
	{
		tmpx += data->player.speed;
		if (data->map1.map[(int)round(data->player.position.y)]
			[(int)round(tmpx)] != '1')
			data->player.position.x = tmpx;
	}
	else if (data->player.angle > (225 * M_PI) / 180
		&& data->player.angle <= (315 * M_PI) / 180)
	{
		tmpx -= data->player.speed;
		if (data->map1.map[(int)round(data->player.position.y)]
			[(int)round(tmpx)] != '1')
			data->player.position.x = tmpx;
	}
}
