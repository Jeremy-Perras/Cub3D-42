/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:09:31 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/05 13:39:11 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *str, unsigned int number, long int length)
{
	while (number > 0)
	{
		str[length--] = 48 + (number % 10);
		number = number / 10;
	}
	return (str);
}

static long int	ft_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char				*str;
	long int			length;
	unsigned int		number;

	length = ft_length(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!(str))
		return (NULL);
	str[length--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_array(str, number, length);
	return (str);
}
