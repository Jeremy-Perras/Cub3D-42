/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:29:18 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 13:45:38 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	buf;
	char	*line;
	int		i;
	int		j;

	i = 1;
	j = 0;
	line = (char *)malloc(sizeof(char *) * 9999);
	if (fd < 0)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0)
			break ;
		line[j++] = buf;
		if (buf == '\n')
			break ;
	}
	line[j] = 0;
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
