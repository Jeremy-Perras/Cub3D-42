/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:56 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/06 08:37:27 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# define HEIGHT 400
# define WIDTH 800

typedef struct t_map
{
	char	**map;
}	t_map;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_position
{
	double	x;
	double	y;
}	t_position;

typedef struct s_player
{
	t_position	position;
	double		speed;
	double		angle;
	double		rot_speed;
}	t_player;

typedef struct s_image
{
	void		*ref;
	t_vector	size;
	char		*addr;
	void		*image;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_window
{
	void		*ref;
	t_vector	size;
}	t_win;

typedef struct s_parse
{
	char	**map;
	int		flag;
	int		count;
	int		n;
	int		s;
	int		e;
	int		w;
	int		f;
	int		c;
	int		player;
}	t_parse;

typedef struct s_raycasting
{
	double	camx;
	double	ratio;
	double	dirx;
	double	diry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	double	stepx;
	double	stepy;
	double	sidedistx;
	double	sidedisty;
	double	perwalldist;
	double	side;
	double	colorfloor;
	double	colorcelling;
}	t_raycasting;

typedef struct s_data
{
	int				im;
	char			*n;
	char			*s;
	char			*e;
	char			*w;
	int				c_r;
	int				c_g;
	int				c_b;
	int				f_r;
	int				f_g;
	int				f_b;
	char			**map2;
	char			**map;
	void			*mlx;
	char			player_orientation;
	t_win			win;
	t_image			*image;
	t_map			map1;
	t_player		player;
	t_raycasting	ray;
}	t_data;

t_data			*ft_parse_map(char *map);
void			ft_texture(char *line, t_parse *parse, t_data *data);
void			exit_error(char *msg);
void			ft_put_one(char **map);
void			ft_puthexa(int b, int *m, char *c);
void			ft_check_map(char **map, t_data *data, int fd);
int				f_color(char *line, t_parse *parse, t_data *data);
int				c_color(char *line, t_parse *parse, t_data *data);
char			**ft_split2(char *str, char *charset);
void			ft_init_parse_and_data(t_parse **parse, t_data **data);
void			ft_lab(char *line, t_parse *parse, t_data *data);
void			ft_parse_line(char *line, t_parse *parse, t_data *data);
void			ft_check_line(char *line, t_parse *parse, t_data *data);
/*
* windows.c
*/
t_win			ft_windows(void *mlx, int widht, int height, char *title);
void			ft_put_background(t_data *data);
void			ft_put_background_init(t_data *data);
void			ft_put_image(t_data *data);
void			ft_image2(t_data *data);
/*
* hook.c
*/
int				key(int key, t_data *data);
void			ft_left_right4(t_data *data, int key);
/*
* recasting.c
*/

void			ft_raycasting(t_data *data);
/*
* recasting2.c
*/
void			ft_draw(t_data *data, int pix, int walltext);
void			ft_distwall(t_data *data);
unsigned int	create_trgb(int t, int r, int g, int b);
void			ft_draw_background(t_data *data);
void			ft_image2(t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, \
				unsigned int color);
#endif
