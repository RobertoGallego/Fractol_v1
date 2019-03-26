/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:29:02 by groberto          #+#    #+#             */
/*   Updated: 2019/03/26 18:53:01 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			deal_key(int keycode, t_fractol *param)
{
	if (keycode == 53)
		exit(0);
	ft_details_and_colors(keycode, param);
	ft_restart(keycode, param);
	ft_move(keycode, param);
	return (0);
}
// zoom minimo quizas
void		ft_details_and_colors(int keycode, t_fractol *param)
{
	if (keycode == 116)
		param->max_itert += 5;
	else if (keycode == 121 && param->max_itert > 5)
		param->max_itert -= 5;
	else if (keycode == 67 && param->depth <= 100)
	{
		param->depth++;
		param->depth = param->depth == 255 ? 0 : param->depth;
	}
	else if (keycode == 15)
	{
		param->r = param->r - 255;
		param->r = param->r == 255 ? 0 : param->r;
	}
	else if (keycode == 5)
	{
		param->g = param->g - 255;
		param->g = param->g == 255 ? 0 : param->g;
	}
	else if (keycode == 11)
	{
		param->b = param->b - 255;
		param->b = param->b == 255 ? 0 : param->b;
	}
	else if (keycode == 13 && param->g >= 13)
	{
		param->g = param->g - 25;
		param->g = param->g == 255 ? 0 : param->g;
		param->b = param->b - 25;
		param->b = param->b == 255 ? 0 : param->b;
	}
	else if (keycode == 75 && param->depth >= 2)
	{
		param->depth--;
		param->depth = param->depth == 0 ? 255 : param->depth;
	}
	mlx_clear_window(param->mlx, param->win);
	make_draw(param);
}

void		ft_restart(int keycode, t_fractol *param)
{
	if ((keycode >= 18 && keycode <= 23) || (keycode >= 83
	&& keycode <= 87) || keycode == 34)
	{
		if (keycode == 34)
			init_draw(param);
		else if (keycode == 18 || keycode == 83)
			param->num = 1;
		else if (keycode == 19 || keycode == 84)
			param->num = 2;
		else if (keycode == 20 || keycode == 85)
			param->num = 3;
		else if (keycode == 21 || keycode == 86)
			param->num = 4;
		else if (keycode == 23 || keycode == 87)
			param->num = 5;
		init_draw(param);
		mlx_clear_window(param->mlx, param->win);
		make_draw(param);
	}
}

void		ft_move(int keycode, t_fractol *param)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 49 || keycode == 8)
	{
		if (keycode == 124)
			param->x1 += 150;
		else if (keycode == 123)
			param->x1 -= 100;
		else if (keycode == 126)
			param->y1 -= 100;
		else if (keycode == 125)
			param->y1 += 100;
		else if (keycode == 49)
		{
			param->julia_motion = param->julia_motion == 1 ? 0 : 1;
		}
		else if (keycode == 8)
		{
			param->stop_color = param->stop_color == 1 ? 0 : 1;
		}
		mlx_clear_window(param->mlx, param->win);
		make_draw(param);
	}
}
