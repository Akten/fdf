/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcherfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 12:56:47 by wcherfi           #+#    #+#             */
/*   Updated: 2017/09/01 13:35:58 by wcherfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int		my_key_func(int keycode, void *mlx, void *win)
{
	printf("key event %d\n", keycode);
	mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	y = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_func, mlx);
	mlx_loop(mlx);
}
