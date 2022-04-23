/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/23 13:30:17 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void ft_texture(char *line, int *flag)
{
	if (ft_strncmp(line, "NO", 2))
		*flag +=
	if (ft_strncmp(line, "NO", 2))
		*flag +=
	if (ft_strncmp(line, "NO", 2))
		*flag +=
	if (ft_strncmp(line, "NO", 2))
		*flag +=
	if (ft_strncmp(line, "NO", 2))
		*flag +=
	if (ft_strncmp(line, "NO", 2))
		*flag +=
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

	if (fd < 0)
	{
		printf("%s: map could not be found\n", ft_strrchr(map, '/');
		exit(1);
	}
	char *line = get_next_line(fd);
	if (!line)
	{
		printf("%s: Empty file\n", ft_strrchr(map, '/');
		exit(1);
	}
	while (line != NULL)
	{
		if (!ft_is_empty_line(line))
			ft_parse_line(line, &flag);
		free(line);
		line = get_next_line(fd);
	}

}

void ft_check_map(char **)
{
		char caracters[] = "01NSEW \t";

	/* Verifie si la ligne ne contient que les caracteres autorises */
		while (line[++i])
		{
			if (!ft_strchr(caracters, line[i]))
			{
				printf("Error: Unexpected catacter: %c", line[i]);
				exit(0);
			}
		}
}
