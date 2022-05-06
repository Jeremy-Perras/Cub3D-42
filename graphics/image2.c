/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:50:11 by jperras           #+#    #+#             */
/*   Updated: 2022/05/06 08:37:20 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if ((x <= WIDTH && x >= 0) && (y >= 0 && y <= HEIGHT))
	{
		dst = data->image[20].addr + (y * data->image[20].line_length
				+ x * (data->image[20].bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	render_rect(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 500)
	{
		j = 0;
		while (j <= 500)
			my_mlx_pixel_put(data, j++, i, color);
		i++;
	}
	return (0);
}
