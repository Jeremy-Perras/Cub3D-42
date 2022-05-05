/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:37:41 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 11:51:42 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_error(char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
		printf("\033[0;33m%c", ft_toupper(msg[i]));
	printf("\n");
	exit(1);
}

void	ft_puthexa(int b, int *m, char *c)
{
	if (b >= 16)
	{
		ft_puthexa(b / 16, m, c);
		ft_puthexa(b % 16, m, c);
	}
	else
	{
		if (b <= 9)
		{
			c[*m] = b + '0';
			*m = *m + 1;
		}
		else
		{
			c[*m] = b + '7';
			*m = *m + 1;
		}
	}
}

void	ft_put_one(char **map)
{
	int	i;
	int	j;

	i = -1;
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

void	ft_init_parse_and_data(t_parse **parse, t_data **data)
{
	*parse = (t_parse *)malloc(sizeof(t_parse));
	(*parse)->map = (char **) malloc(sizeof(char **) * 1000);
	(*parse)->flag = 0;
	(*parse)->count = 0;
	(*parse)->n = 0;
	(*parse)->s = 0;
	(*parse)->e = 0;
	(*parse)->w = 0;
	(*parse)->f = 0;
	(*parse)->c = 0;
	(*parse)->player = 0;
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->map = (char **)malloc(sizeof(char **) * 1000);
}
