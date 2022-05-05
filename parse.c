/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 11:45:15 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_line(char *line, t_parse *parse, t_data *data)
{
	char	*caracters;
	char	*player;
	int		i;

	caracters = "01NSEW \t";
	player = "NSEW";
	i = 0;
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

static int	ft_is_empty_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
	}
	return (1);
}

static void	check_data(t_parse **parse, t_data **data, int *fd, char *map)
{
	ft_init_parse_and_data(parse, data);
	*fd = open(map, O_RDONLY);
	if (*fd < 0)
		exit_error("Map could not be found");
}

t_data	*ft_parse_map(char *map)
{
	int		fd;
	t_parse	*parse;
	char	*line;
	t_data	*data;

	check_data(&parse, &data, &fd, map);
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
	ft_check_map(parse->map, data, fd);
	data->map2 = parse->map;
	return (data);
}
