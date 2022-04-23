/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:02:29 by jperras           #+#    #+#             */
/*   Updated: 2022/04/23 13:48:25 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int main(void)
{
  t_data  data;

  data.mlx = mlx_init();
  data.win = ft_windows(data.mlx, 1920, 1080, "test");
  mlx_key_hook(data.win.ref, key, &data);
  mlx_loop(data.mlx);
}
