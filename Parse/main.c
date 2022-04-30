/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:32:58 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/30 14:59:50 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int main(int ac, char **av)
{
	t_data *data;

	if (ac != 2)
		return (printf("Error\nInsufficient number of arguments"));
	if (!(ft_strrchr(av[1], '.')) || ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 4) != 0)
		return (printf("Error\n Invalid map extension\n"));
	data = ft_parse_map(av[1]);
	printf("%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", data->n, data->s, data->e, data->w, data->c_r, data->c_g, data->c_b, data->f_r, data->f_g, data->f_b);
	int i = -1;
	while (data->map[++i])
		printf("%s\n", data->map[i]);
}
