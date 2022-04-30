/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:56 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/30 14:56:07 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

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
} t_parse;

typedef struct s_data
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	int		c_r;
	int		c_g;
	int		c_b;
	int		f_r;
	int		f_g;
	int		f_b;
	char 	**map;
} t_data;

t_data 	*ft_parse_map(char *map);
void 	ft_texture(char *line, t_parse *parse, t_data *data);
void  	exit_error(char *msg);
void 	ft_check_map(char **map);
int 	f_color(char *line, t_parse *parse, t_data *data);
int 	c_color(char *line, t_parse *parse, t_data *data);


#endif
