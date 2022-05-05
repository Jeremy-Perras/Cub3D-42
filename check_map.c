/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:54 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/04 17:56:35 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
}

// static void ft_check_horizontal(char *line)
// {
// 	int	i;
//
// 	i = 0;
// 	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
// 		i++;
// 	if (line[i] != '1')
// 		exit_error("Invalid map: walls must be closed");
// 	while(line[i] && i < (int)ft_strlen(line))
// 	{
// 		if (line[i] == ' ' || line[i] == '\t')
// 		{
// 			if (line[i - 1] == '0' || line[i + 1] == '0')
// 			{
// 				printf("%s\n", line);
// 				printf("%c %c %c\n", line[i - 1], line[i], line[i + 1]);
// 				printf("%d\n", i);
// 				exit_error("Invalid map: Inner walls must be closed");
// 			}
// 		}
// 		i++;
// 	}
// 	if (line[--i] != '1')
// 		exit_error("Invalid map: walls must be closed");
// }
//
// static int get_height(char **map)
// {
// 	int i;
//
// 	i = 0;
// 	while (map[i])
// 		i++;
// 	return (i);
// }
//
// static int get_height_line(char **map, int i, int j, int height)
// {
// 	int height_line;
//
// 	height_line = 0;
// 	while (map[i] && i < height)
// 	{
// 		if (map[i][j] == '0' || map[i][j] == '1')
// 		{
// 			height_line++;
// 		}
// 		i++;
// 	}
// 	return (height_line);
// }
//
//
// static void ft_check_vertical(char **map)
// {
// 	int i;
// 	int j;
// 	int height;
// 	int height_line;
//
// 	i = 0;
// 	j = -1;
// 	height = get_height(map);
// 	printf("heitght: %d\n", height);
// 	while (map[i][++j])
// 	{
// 		i = 0;
// 		height_line = get_height_line(map, i, j, height);
// 		printf("height_line: %d\n", height_line);
// 		while (map[i] && (map[i][j] == ' ' || map[i][j] == '\t'))
// 				i++;
// 		if (map[i] && map[i][j] != '1')
// 				exit_error("Invalid map: North wall isn't closed");
// 		while (map[i] && map[i][j] && map[i + 1] && map[i + 1][j])
// 		{
// 			if (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
// 				if (map[i - 1][j] == '0' || map[i + 1][j] == '0')
// 					exit_error("Invalid map: Inner walls must be closed2");
// 			i++;
// 		}
// 		if (map[height] && map[height][j] && map[height][j] != '1')
// 			exit_error("Invalid map: South walls must be closed");
// 	}
// }

static void check_player(char **map, t_data *data)
{
	int	i;
	int	j;
	int count;
	char player[5] = "NSEW";

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

static void ft_check_zero(char **map)
{
	int i = -1;
	int j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
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
					{
						printf("i:%d j:%d map[i][j]%c", i, j, map[i][j]);
										exit_error("Walls must be closed AAA");
					}
			}
		}
	}
}

void ft_check_map(char **map, t_data *data)
{
	int i;

	map = ft_trim_map(map);
	check_player(map, data);
	i = -1;
	ft_check_zero(map);
	// while (map[++i])
	// 	ft_check_horizontal(map[i]);
	// ft_check_vertical(map);
}
