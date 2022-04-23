/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:50:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/23 14:10:42 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void n_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
	{
		printf("Error: North texture's path cannot be found");
		exit(1);
	}
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
}

void s_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
	{
		printf("Error: South texture's path cannot be found");
		exit(1);
	}
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
}

void w_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
	{
		printf("Error: West texture's path cannot be found");
		exit(1);
	}
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
}

void e_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
	{
		printf("Error: East texture's path cannot be found");
		exit(1);
	}
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
}

void fc_texture(char *line)
{
	int fd;
	int i;
	char **path;

	path = ft_split(line, ' ');
	fd = open(path[1], O_RDONLY)
	if (fd < 0)
	{
		printf("Error: North texture's path cannot be found");
		exit(1);
	}
	close(fd);
	i = -1;
	while (path[++i])
		free(path[i])
	free(path);
}
