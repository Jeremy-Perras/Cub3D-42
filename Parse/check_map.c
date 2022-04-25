/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:54 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/25 12:16:12 by dhaliti          ###   ########.fr       */
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
			j--
		}
	}
	return (map);
}

static void ft_check_spaces(char *line, int index)
{
	if (line[index - 1] != '1' || line[index + 1] != '1')
		exit_error("Invalid map: walls must be closed");
}

static void ft_check_horizontal(char *line)
{
	int	i

	i = 0;

	while (line[i] && (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != 1)
		exit_error("Invalid map: walls must be closed");
	while(line[i] && i < ft_strlen(line))
	{
		if (line[i] == ' ' || line[i] == '\t')
			ft_check_spaces(line, i);
		i++;
	}
	if (line[i] != 1)
		exit_error("Invalid map: walls must be closed");

static void ft_check_vertical(char **map)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (map[i][++j])
	{
		i = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
				i++;
		if (map[i][j] != 1)
			exit_error("Invalid map: walls must be closed");
		while (map[i][j])
		{
			if (map[i][j] == ' ' || map[i][j] == '\t')
			{
				if (map[i][j - 1] != '1' || map[i][j + 1] != '1')
					exit_error("Invalid map: walls must be closed");
				i++;
			}
		if (map[i][j] != 1)
			exit_error("Invalid map: walls must be closed");
		}
	}
}

void ft_check_map(char **map)
{
	int i;
	int j;

	map = ft_trim_map(map);
	i = -1;
	while (map[++i])
		ft_check_horizontal(map[i]);
	ft_check_vertical(map);
}
