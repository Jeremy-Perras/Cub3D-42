/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 10:41:44 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void ft_check_line(char *line, t_parse *parse, t_data *data)
{
	char caracters[] = "01NSEW \t";
	char player[] = "NSEW";
	int i = 0;

	while (line[++i])
	{
		if (ft_strchr(player, line[i]))
		{
			parse->player++;
			data->player_orientation = line[i];
		}
		if (!ft_strchr(caracters, line[i]) || parse->player > 1)
			exit_error("Error: Unexpected catacter");
	}
}

static void ft_lab(char *line, t_parse *parse, t_data *data)
{
	static int x = 0;
	parse->count = 1;
	line[ft_strlen(line) - 1] = '\0';
	parse->map[x] = ft_strdup(line);
 	ft_check_line(line, parse, data);
	line[ft_strlen(line) - 1] = '1';
	data->map2[x] = ft_strdup(line);
	x++;
	parse->map[x] = NULL;
	data->map2[x] = NULL;
}

static void ft_parse_line(char *line, t_parse *parse, t_data *data)
{
	if (parse->flag == 6)
		ft_lab(line, parse, data);
	else
		ft_texture(line, parse, data);
}

static int ft_is_empty_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] !=  ' ' && line[i] != '\t' && line[i] != '\n')
			return(0);
	}
	return (1);
}


static void ft_init_parse_and_data(t_parse **parse, t_data **data)
{
	*parse           = (t_parse *)malloc(sizeof(t_parse));
	(*parse)->map    = (char **) malloc(sizeof(char **) * 1000);
	(*parse)->flag   = 0;
	(*parse)->count  = 0;
	(*parse)->n      = 0;
	(*parse)->s      = 0;
	(*parse)->e      = 0;
	(*parse)->w      = 0;
	(*parse)->f      = 0;
	(*parse)->c      = 0;
	(*parse)->player = 0;
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->map2 = (char **)malloc(sizeof(char **) * 1000);
}

static void ft_put_one(char **map)
{
	int i = -1;
	int j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ' || map[i][j] == '\t')
				map[i][j] = '1';
		}
	}
}


t_data *ft_parse_map(char *map)
{
	int 	fd;
	t_parse *parse;
	char 	*line;
	t_data	*data;

	ft_init_parse_and_data(&parse, &data);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Map could not be found");
	line = get_next_line(fd);
	if (!line)
		exit_error("Map is empty");
	while (line != NULL)
	{
		if (ft_is_empty_line(line) && parse->count)
			exit_error("Invalid map");
		if (!ft_is_empty_line(line))
			ft_parse_line(line, parse, data);
		free(line);
		line = get_next_line(fd);
	}
	if (parse->flag != 6 || !parse->n || !parse->s || !parse->e
			|| !parse->w || !parse->f || !parse->c || parse->player != 1)
		exit_error("Invalid texture or player");
	ft_check_map(parse->map, data);
	data->map = parse->map;
	ft_put_colors(data);
	ft_put_one(data->map2);
	close(fd);
	return (data);
}
