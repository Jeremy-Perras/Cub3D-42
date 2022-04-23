/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:50:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/23 15:05:55 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int n_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
		exit_error("Error: North texture's path cannot be found");
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
	return (1);
}

int s_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
		exit_error("Error: South texture's path cannot be found");
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
	return (1);
}

int w_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
		exit_error("Error: West texture's path cannot be found");
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
	return (1);
}

int e_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
		exit_error("Error: East texture's path cannot be found");
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
	return (1);
}

int fc_texture(char *line)
{
	int i;
	char **cmd;
	char **rgb;

	cmd = ft_split(line, ' ');
	if (!cmd[1])
		exit_error("Error: Ceiling and floor color values missing");
	rgb = ft_split(cmd[1], ',');
	if (!rgb[1] || !rgb[2])
		exit_error("Error: Ceiling and floor color values missing");
	i = -1;
	while (rgb[++i])
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			exit_error("Ceiling or floor invalid color values");
		free(rgb[i]);
		if (cmd[i])
			free(cmd[i]);
	}
	free(rgb);
	free(cmd);
}
