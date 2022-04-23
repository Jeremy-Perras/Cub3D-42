/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/23 15:08:44 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void ft_build_lab(char *line)
{
	static int x = 0;

	data->map[x] = ft_strdup(line);
	x++;
	data->map[x] = NULL;
}

static void ft_lab(char *line)
{
 	ft_check_line_carac(line);
	ft_build_lab(line);
}


static void ft_texture(char *line, int *flag)
{
	if (ft_strncmp(line, "NO", 2))
		*flag += n_texture(line);
	if (ft_strncmp(line, "SO", 2))
		*flag += s_texture(line);
	if (ft_strncmp(line, "WE", 2))
		*flag += w_texture(line);
	if (ft_strncmp(line, "EA", 2))
		*flag += e_texture(line);
	if (ft_strncmp(line, "F", 1))
		*flag += fc_texture(line);
	if (ft_strncmp(line, "C", 1))
		*flag += fc_texture(line);
}

static void ft_parse_line(char *line, int *flag)
{
	if (*flag == 6)
		ft_lab(line);
	else
		ft_texture(line, flag);
}

static int ft_is_empty_line(cahr *line)
{
	i = -1;
	while (line[++i])
	{
		if (line[i] !=  ' ' && line[i] != '\t')
			return(0);
	}
	return (1);
}


void ft_parse_map(char *map)
{
	int fd = open(map, O_RDONLY);
	int flag = 0;
	int count = 0;

	if (fd < 0)
		exit_error("Map could not be found");
	char *line = get_next_line(fd);
	if (!line)
		exit_error("Map is empty");
	while (line != NULL)
	{
		if (ft_is_empty_line && count)
			exit_error("Invalid map");
		if (!ft_is_empty_line(line))
			ft_parse_line(line, &flag, & count);
		free(line);
		line = get_next_line(fd);
	}
	if (flag != 6)
		exit_error("Textures missgin in map");
}

void ft_check_line_carac(char **)
{
		char caracters[] = "01NSEW \t";

		while (line[++i])
		{
			if (!ft_strchr(caracters, line[i]))
				exit_error("Error: Unexpected catacter");
		}
}
