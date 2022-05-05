/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:29:18 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 14:03:38 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init(int *i, int *j, char **line)
{
	*i = 1;
	*j = 0;
	*line = (char *)malloc(sizeof(char *) * 9999);
}

char	*get_next_line(int fd)
{
	char	buf;
	char	*line;
	int		i;
	int		j;

	ft_init(&i, &j, &line);
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
