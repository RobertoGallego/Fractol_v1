/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:07:33 by groberto          #+#    #+#             */
/*   Updated: 2019/03/26 18:46:49 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx(t_fractol *first)
{
	first->mlx = mlx_init();
	first->win = mlx_new_window(first->mlx, WIDTH, HEIGHT, "Fractol");
	first->img = mlx_new_image(first->mlx, WIDTH, HEIGHT);
	first->data = mlx_get_data_addr(first->img, &(first->bpp),
	&(first->sizeline), &(first->endian));
	init_draw(first);
	make_draw(first);
	mlx_hook(first->win, 2, 0, deal_key, first);
	mlx_hook(first->win, 4, 0, mouse_hook, first);
	mlx_hook(first->win, 6, 0, mouse_motion, first);
	mlx_loop(first->mlx);
	return (0);
}

void	info_available(void)
{
	ft_putendl("usage: ./fractol <number>");
	ft_putendl("1 = Mandelbrot");
	ft_putendl("2 = Julia");
	ft_putendl("3 = Burningship");
	ft_putendl("4 = Douady");
	ft_putendl("5 = Delbrotmal");
}

void	init_draw(t_fractol *first)
{
	first->x1 = WIDTH;
	first->y1 = HEIGHT;
	first->zoom = 300;
	first->max_itert = 40;
	first->r = 255;
	first->g = 255;
	first->b = 255;
	first->depth = 1;
	first->julia_motion = 1;
	first->stop_color = 1;
}

void	make_draw(t_fractol *func)
{
	func->x = 0;
	while (func->x < WIDTH)
	{
		func->y = 0;
		while (func->y < HEIGHT)
		{
			if (func->num == 1)
				ft_maldelbrot(func);
			else if (func->num == 2)
				ft_julia(func);
			else if (func->num == 3)
				ft_burningship(func);
			else if (func->num == 4)
				ft_douady(func);
			else if (func->num == 5)
				ft_delbrotmal(func);
			func->y++;
		}
		func->x++;
	}
	mlx_put_image_to_window(func->mlx, func->win, func->img, 0, 0);
	info(func);
}

int		main(int argc, char *argv[])
{
	t_fractol first;

	first.num = 0;
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "1") == 0)
			first.num = 1;
		else if (ft_strcmp(argv[1], "2") == 0)
			first.num = 2;
		else if (ft_strcmp(argv[1], "3") == 0)
			first.num = 3;
		else if (ft_strcmp(argv[1], "4") == 0)
			first.num = 4;
		else if (ft_strcmp(argv[1], "5") == 0)
			first.num = 5;
		if (first.num)
			mlx(&first);
		else
			info_available();
	}
	else
		info_available();
	return (0);
}
