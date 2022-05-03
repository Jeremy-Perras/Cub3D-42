
// 
//
// #include "cub.h"
// int		put_pxl(t_data *data, int x, int y, unsigned int c)
// {
//  char		*dest;
//
//  dest = data->image[12].addr + (y * data->image[data->im ].line_length + x * (data->image[data->im].bits_per_pixel / 8));
//  *(unsigned int *)dest = c;
//  return (0);
// }
//
// int render_rect2(t_data *data, int color)
// {
//  int	i;
//  int j;
//
//  i = 0;
//
//  while (i <= 500)
//  {
//    j = 0;
//    while (j <=  500)
//    put_pxl(data, j++, i, color);
//    ++i;
//  }
//  return (0);
// }
//
//
// int main(int argc, char **av)
// {
//   t_data *data;
//   unsigned int color;
//   (void) argc;
//
//   data = ft_parse_map(av[1]);
//
//   data->mlx = mlx_init();
//   data->win = ft_windows(data->mlx, Width ,Height , "test");
//   ft_put_image(data);
//   data->image[12].image = mlx_new_image(data->mlx, 1000, 500);
//   data->image[10].image = mlx_new_image(data->mlx, 500, 500);
//   data->image[10].addr = mlx_get_data_addr(data->image[10].image, &(data->image[10].bits_per_pixel),
//     &(data->image[10].line_length), &(data->image[10].endian));
//   data->image[12].addr = mlx_get_data_addr(data->image[12].image, &(data->image[12].bits_per_pixel),
//       &(data->image[12].line_length), &(data->image[12].endian));
//   color = *(unsigned int *)(data->image[9].addr +
// 		0);
//     // color = create_trgb(0, data->f_r, data->f_g, data->f_b);
//
//
//
//   data->im = 10;
//   render_rect2(data, color);
//   mlx_put_image_to_window(data->mlx, data->win.ref, data->image[12].image, 0 , 0);
//   mlx_loop(data->mlx);
//
// }
