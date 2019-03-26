/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:55:39 by groberto          #+#    #+#             */
/*   Updated: 2019/03/26 18:51:15 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_motion(int x, int y, t_fractol *param)
{
	if (param->julia_motion == 1)
	{
		param->x2 = ((double)x - WIDTH / 2) / (double)(param->zoom / 2);
		param->y2 = ((double)y - HEIGHT / 2) / (double)(param->zoom / 2);
	}
	make_draw(param);
	return (0);
}

int			mouse_hook(int keycode, int x, int y, t_fractol *param)
{
	if (keycode == 4 || keycode == 1)
	{
		if (x < WIDTH && y < HEIGHT && y > 0)
		{
			param->xz = x - (param->x1 / 2);
			param->yz = y - (param->y1 / 2);
			param->x1 -= param->xz;
			param->y1 -= param->yz;
			param->zoom *= 1.5;
		}
	}
	if (keycode == 5 || keycode == 2)
	{
		if (x < WIDTH && y < HEIGHT && y > 0)
		{
			param->xz = x - (param->x1 / 2);
			param->yz = y - (param->y1 / 2);
			param->x1 += param->xz;
			param->y1 += param->yz;
			param->zoom /= 2;
		}
	}
	mlx_clear_window(param->mlx, param->win);
	make_draw(param);
	return (0);
}

void		info(t_fractol *param)
{
	mlx_string_put(param->mlx, param->win, 10, 5, 0x2A2A2A,
			"MOVE = ^ v < >");
	mlx_string_put(param->mlx, param->win, 10, 20, 0x2A2A2A,
			"DETAILS = up down");
	mlx_string_put(param->mlx, param->win, 10, 35, 0x2A2A2A,
			"SATURATION = W");
	mlx_string_put(param->mlx, param->win, 10, 50, 0x2A2A2A,
			"COLOR = R G B");
	mlx_string_put(param->mlx, param->win, 10, 65, 0x2A2A2A,
			"BRIGHT = / *");
	mlx_string_put(param->mlx, param->win, 10, 80, 0x2A2A2A,
			"STOP = Space");
	mlx_string_put(param->mlx, param->win, 10, 95, 0x2A2A2A,
			"RESTART = i");
	mlx_string_put(param->mlx, param->win, 10, 110, 0x2A2A2A,
			"QUIT = esc");
}
