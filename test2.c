#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
  (void) x;
  (void) y;


  dst = data->image[11].addr + (y * data->image[11].line_length + x * (data->image[11].bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

 int render_rect(t_data *data)
 {
 	int	i;
 	int j;

 	i = 0;
  int color;
  color = create_trgb(0, data->f_r, data->f_g, data->f_b);
 	while (i <= 500)
 	{
 		j = 0;
		while (j <=  500)
 		my_mlx_pixel_put(data, j++, i, color);
 		++i;
 	}
 	return (0);
 }

void ft_image2(t_data *data)
{

	data->image[11].image = mlx_new_image(data->mlx, 500, 500);
  data->image[11].addr = mlx_get_data_addr(data->image[11].image, &(data->image[11].bits_per_pixel),
    &(data->image[11].line_length), &(data->image[11].endian));
  render_rect(data);
}
