/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:35:11 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 11:46:52 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_strs(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_lab(char *line, t_parse *parse, t_data *data)
{
	static int	x = 0;

	parse->count = 1;
	line[ft_strlen(line) - 1] = '\0';
	parse->map[x] = ft_strdup(line);
	ft_check_line(line, parse, data);
	line[ft_strlen(line)] = '1';
	data->map[x] = ft_strdup(line);
	x++;
	parse->map[x] = NULL;
	data->map[x] = NULL;
}

void	ft_parse_line(char *line, t_parse *parse, t_data *data)
{
	if (parse->flag == 6)
		ft_lab(line, parse, data);
	else
		ft_texture(line, parse, data);
}

int	f_color(char *line, t_parse *parse, t_data *data)
{
	int		i;
	char	**cmd;
	char	**rgb;

	cmd = ft_split(line, ' ');
	if (!cmd[1])
		exit_error("Error: Ceiling and floor color values missing");
	rgb = ft_split(cmd[1], ',');
	if (!rgb[1] || !rgb[2])
		exit_error("Error: Ceiling and floor color values missing");
	data->f_r = ft_atoi(rgb[0]);
	data->f_g = ft_atoi(rgb[1]);
	data->f_b = ft_atoi(rgb[2]);
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			exit_error("Ceiling or floor invalid color values");
		free(rgb[i]);
	}
	parse->f++;
	free(rgb);
	free_strs(cmd);
	return (1);
}

int	c_color(char *line, t_parse *parse, t_data *data)
{
	int		i;
	char	**cmd;
	char	**rgb;

	cmd = ft_split(line, ' ');
	if (!cmd[1])
		exit_error("Error: Ceiling and floor color values missing");
	rgb = ft_split(cmd[1], ',');
	if (!rgb[1] || !rgb[2])
		exit_error("Error: Ceiling and floor color values missing");
	data->c_r = ft_atoi(rgb[0]);
	data->c_g = ft_atoi(rgb[1]);
	data->c_b = ft_atoi(rgb[2]);
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			exit_error("Ceiling or floor invalid color values");
		free(rgb[i]);
	}
	parse->c++;
	free(rgb);
	free_strs(cmd);
	return (1);
}
