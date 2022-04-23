/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/23 18:35:33 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void ft_check_line(char *line, t_parse *parse)
{
	char caracters[] = "01NSEW \t";
	char player[] = "NSEW";
	int i = 0;

	while (line[++i])
	{
		if (ft_strchr(player, line[i]))
			parse->player++;
		if (!ft_strchr(caracters, line[i]) || parse->player > 1)
			exit_error("Error: Unexpected catacter");
	}
}

static void ft_lab(char *line, t_parse *parse)
{
	static int x = 0;
	parse->count = 1;
	line[ft_strlen(line) - 1] = '\0';
 	ft_check_line(line, parse);
	parse->map[x] = ft_strdup(line);
	x++;
	parse->map[x] = NULL;
}

static void ft_parse_line(char *line, t_parse *parse)
{
	if (parse->flag == 6)
		ft_lab(line, parse);
	else
		ft_texture(line, parse);
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


static void ft_init_parse(t_parse **parse)
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
}


char **ft_parse_map(char *map)
{
	int 	fd;
	t_parse *parse;

	ft_init_parse(&parse);
	printf("PARSE INIT\n");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Map could not be found");
	char *line = get_next_line(fd);
	if (!line)
		exit_error("Map is empty");
	while (line != NULL)
	{
		if (ft_is_empty_line(line) && parse->count)
			exit_error("Invalid map");
		if (!ft_is_empty_line(line))
			ft_parse_line(line, parse);
		free(line);
		line = get_next_line(fd);
	}
	if (parse->flag != 6 || !parse->n || !parse->s || !parse->e
			|| !parse->w || !parse->f || !parse->c)
		exit_error("Textures missing in map");
	return (parse->map);
}
