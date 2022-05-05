/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:54 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 13:56:40 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
static char **ft_trim_map(char **map)
{
	int i = -1;
	int j;

	while (map[++i])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] != '1' && map[i][j] != '0')
		{
			map[i][j] = '\0';
			j--;
		}
	}
	return (map);
}*/

/*
map = ft_trim_map(map);*/

static void	check_player(char **map, t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	*player;

	player = "NSEW";
	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr(player, map[i][j]))
			{
				data->player.position.x = j;
				data->player.position.y = i;
				map[i][j] = '0';
				count++;
			}
		}
	}
	if (count != 1)
		exit_error("Too many or no player");
}

static void	ft_zeroes(char **map, int i, int j)
{
	if (!map[i + 1][j] || (map[i + 1][j] != '1'
		&& map[i + 1][j] != '0')
		|| !map[i - 1][j] || (map[i - 1][j] != '1'
		&& map[i - 1][j] != '0')
		|| !map[i][j - 1] || (map[i][j - 1] != '1'
		&& map[i][j - 1] != '0')
		|| !map[i][j + 1] || (map[i][j + 1] != '1'
		&& map[i][j + 1] != '0')
		|| !map[i + 1][j + 1] || (map[i + 1][j + 1] != '1'
		&& map[i + 1][j + 1] != '0') || !map[i - 1][j + 1]
		|| (map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '0')
		|| !map[i + 1][j - 1] || (map[i + 1][j - 1] != '1'
		&& map[i + 1][j - 1] != '0') || !map[i + 1][j + 1]
		|| (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '0'))
		exit_error("Walls must be closed");
}

static void	ft_check_zero(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				ft_zeroes(map, i, j);
		}
	}
}

void	ft_check_map(char **map, t_data *data, int fd)
{
	int	i;

	close(fd);
	check_player(map, data);
	i = -1;
	ft_check_zero(map);
	ft_put_one(data->map);
}
