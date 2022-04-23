/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:56 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/23 18:31:04 by dhaliti          ###   ########.fr       */
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

char **ft_parse_map(char *map);
void ft_texture(char *line, t_parse *parse);
void exit_error(char *msg);


#endif
