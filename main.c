/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:32:51 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 16:12:39 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	utils_create(void *mlx_ptr, int argc, t_fractal *fractals)
{
	int i;

	i = 1;
	while (i < argc)
	{
		fractals[i - 1].mlx_ptr = mlx_ptr;
		i++;
	}
}

static void	initiate_fractals(void *mlx_ptr, int argc, char **argv)
{
	int					i;
	static t_fractal	fractals[6];

	i = 1;
	utils_create(mlx_ptr, argc, fractals);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "mandelbrot") == 0)
			fractals[i - 1].fractal_type = mandelbrot;
		else if (ft_strcmp(argv[i], "julia") == 0)
			fractals[i - 1].fractal_type = julia;
		else if (ft_strcmp(argv[i], "burning_ship") == 0)
			fractals[i - 1].fractal_type = ship;
		else if (ft_strcmp(argv[i], "spider") == 0)
			fractals[i - 1].fractal_type = spider;
		else if (ft_strcmp(argv[i], "irina") == 0)
			fractals[i - 1].fractal_type = irina;
		else if (ft_strcmp(argv[i], "branches") == 0)
			fractals[i - 1].fractal_type = branches;
		fractals[i - 1].transform.guide_visible = 1;
		draw_fractal(&fractals[i - 1]);
		i++;
	}
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;

	arguments_check(argc, argv);
	mlx_ptr = mlx_init();
	initiate_fractals(mlx_ptr, argc, argv);
	mlx_loop(mlx_ptr);
	return (0);
}
