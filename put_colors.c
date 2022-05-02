/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:37:18 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/02 12:37:14 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_put_colors(t_data *data)
{
	char r[3] = {'0', '0'};
	char b[3] = {'0', '0'};
	char g[3] = {'0', '0'};
	char *floor;
	char *ceiling;
	int m = 0;
	int fd;
	int fd2;

	ft_puthexa(data->f_r, &m, r);
	m = 0;
	ft_puthexa(data->f_g, &m, g);
	m = 0;
	ft_puthexa(data->f_b, &m, b);
	floor = ft_strjoin(r, ft_strjoin(g, b));
	m = 0;
	ft_puthexa(data->c_r, &m, r);
	m = 0;
	ft_puthexa(data->c_g, &m, g);
	m = 0;
	ft_puthexa(data->c_b, &m, b);
	ceiling = ft_strjoin(r, ft_strjoin(g, b));
	fd = open("./image/f.xpm", O_WRONLY);
	fd2 = open("./image/c.xpm", O_WRONLY);
	if (fd < 0 || fd2 < 0)
		exit_error("floor error");
	ft_putstr_fd("static char *thor[] = {\"5 5 1 1 \", \"  c #", fd);
	ft_putstr_fd(floor, fd);
	ft_putstr_fd(",", fd);
	int i = -1;
	while (++i < 5)
	{
		ft_putstr_fd("\"     \"", fd);
		if (i < 4)
			ft_putstr_fd(",\n", fd);
	}
	ft_putstr_fd("};", fd);
	close(fd);
	ft_putstr_fd("static char *ceiling = {\"5 5 1 1 \", \"  c #", fd2);
	ft_putstr_fd(ceiling, fd2);
	ft_putstr_fd(",\",", fd2);
	i = -1;
	while (++i < 5)
	{
		ft_putstr_fd("\"     \"", fd2);
		if (i < 4)
			ft_putstr_fd(",\n", fd2);
	}
	ft_putstr_fd("};", fd2);
	close(fd2);
}
