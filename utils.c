/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:37:41 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/02 11:34:58 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void exit_error(char *msg)
{
	int i;

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
