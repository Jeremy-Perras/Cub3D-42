/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:50:11 by jperras           #+#    #+#             */
/*   Updated: 2022/05/05 09:14:46 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if( x <= Width && x >= 0 && y >= 0 && y <= Height)
	{
  	dst = data->image[20].addr + (y * data->image[20].line_length +
			x * (data->image[20].bits_per_pixel / 8));
			*(unsigned int*)dst = color;
	}
}

 int render_rect(t_data *data, int color)
 {
 	int	i;
 	int j;

 	i = 0;

 	while (i <= 500)
 	{
 		j = 0;
		while (j <=  500)
 		my_mlx_pixel_put(data, j++, i, color);
 		++i;
 	}
 	return (0);
 }
 //
 // int		put_pxl(t_display *display, int x, int y, unsigned int c)
 // {
 // 	char		*dest;
 //
 // 	dest = display->pxl + display->s_line * y + x * (display->bpp / 8);
 // 	*(unsigned int *)dest = c;
 // 	return (0);
 // }

void ft_image2(t_data *data)
{
	int color;

	color = create_trgb(0, data->f_r, data->f_g, data->f_b);

		data->im = 11;
  render_rect(data, color);
	color = create_trgb(0, data->f_r, data->f_g, data->f_b);

	data->im = 12;
  render_rect(data, color);
	// data->image[10].addr = mlx_get_data_addr(data->image[10].image, &(data->image[10].bits_per_pixel),
  //   &(data->image[10].line_length), &(data->image[10].endian));
	// 	display->color = *(unsigned int *)(display->ptr[display->textnum] +
	// 	display->s_line2[display->textnum] * display->texywall +
	// 	display->texxwall * (display->bpp2[display->textnum] / 8));
	// 	put_pxl(display, x, y, display->color);
}
