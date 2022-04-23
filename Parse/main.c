/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:32:58 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/23 17:21:09 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int main(int ac, char **av)
{
	char **map;

	if (ac != 2)
		return (printf("Error\nInsufficient number of arguments"));
	printf("ARGS OK\n");
	if (!(ft_strrchr(av[1], '.')) || ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 4) != 0)
		return (printf("Error\n Invalid map extension\n"));
	map = ft_parse_map(av[1]);
	int i = -1;
	while(map[++i])
		printf("%s\n", map[i]);
}
