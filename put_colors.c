/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:37:18 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/02 11:53:13 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_put_colors(t_data *data)
{
	char r[2] = {"0", "0"};
	char b[2] = {"0", "0"};
	char g[2] = {"0", "0"};
	char *floor;
	char *ceiling;
	int m;
	int fd;

	ft_puthexa(data->f_r, &m, r);
	ft_puthexa(data->f_g, &m, g);
	ft_puthexa(data->f_b, &m, b);
	floor = ft_strjoin(r, ft_strjoin(g, b));
	printf("%s\n", floor);
	fd = open("p./images/p.xml", O_WRONLY);
	if (fd < 0)
		exit_error("floor error");
	ft_putstr_fd("static char *_ee5d38949fd4231cdd0f319b3c19ae9VHAnEG3g9guP", fd)
	ft_putstr_fd("SbUe[] = {\"50 50 1 1 \", \"  c #", fd);
	ft_putstr_fd(floor, fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(",", fd);
	int i = 0;
	while (i < 50)
	{
		ft_putstr_fd("                                                  ", fd);
		i++;
	}
	close(fd);
}
