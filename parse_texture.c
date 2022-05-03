/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:50:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/03 17:47:08 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int n_texture(char *line, t_parse *parse, t_data *data)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	path[1][ft_strlen(path[1]) - 1] = '\0';
	fd = open(path[1], O_RDONLY);
	if (fd < 0 || path[2])
		exit_error("Error: North texture's path cannot be found");
	close(fd);
	data->n = ft_strdup(path[1]);
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
	parse->n = 1;
	return (1);
}

static int s_texture(char *line, t_parse *parse, t_data *data)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	path[1][ft_strlen(path[1]) - 1] = '\0';
	fd = open(path[1], O_RDONLY);
	if (fd < 0 || path[2])
		exit_error("Error: South texture's path cannot be found");
	close(fd);
	data->s = ft_strdup(path[1]);
	i = -1;
	while (path[++i])
		free(path[i]);
	parse->s = 1;
	free(path);
	return (1);
}

static int w_texture(char *line, t_parse *parse, t_data *data)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	path[1][ft_strlen(path[1]) - 1] = '\0';
	fd = open(path[1], O_RDONLY);
	printf("%s\n", path[1]);
	if (fd < 0 || path[2])
		exit_error("Error: West texture's path cannot be found");
	close(fd);
	data->w = ft_strdup(path[1]);
	i = -1;
	while (path[++i])
		free(path[i]);
	parse->w = 1;
	free(path);
	return (1);
}

static int e_texture(char *line, t_parse *parse, t_data * data)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	path[1][ft_strlen(path[1]) - 1] = '\0';
	fd = open(path[1], O_RDONLY);
	if (fd < 0)
		exit_error("Error: East texture's path cannot be found");
	close(fd);
	data->e = ft_strdup(path[1]);
	i = -1;
	while (path[++i])
		free(path[i]);
	parse->e = 1;
	free(path);
	return (1);
}

void ft_texture(char *line, t_parse *parse, t_data *data)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		parse->flag += n_texture(line, parse, data);
	if (ft_strncmp(line, "SO", 2) == 0)
		parse->flag += s_texture(line, parse, data);
	if (ft_strncmp(line, "WE", 2) == 0)
		parse->flag += w_texture(line, parse, data);
	if (ft_strncmp(line, "EA", 2) == 0)
		parse->flag += e_texture(line, parse, data);
	if (ft_strncmp(line, "F", 1) == 0)
		parse->flag += f_color(line, parse, data);
	if (ft_strncmp(line, "C", 1) == 0)
		parse->flag += c_color(line, parse, data);
}
