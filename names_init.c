/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:32:58 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 15:33:00 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	names_init_2(t_fractal *fractal)
{
	if (fractal->fractal_type == ship)
	{
		ft_strcpy(fractal->file_name, "kernels/ship_kernel.cl\0");
		ft_strcpy(fractal->win_name, "Burning Ship\0");
		ft_strcpy(fractal->kernel_name, "ship\0");
	}
	else if (fractal->fractal_type == spider)
	{
		ft_strcpy(fractal->file_name, "kernels/spider_kernel.cl\0");
		ft_strcpy(fractal->win_name, "Spider\0");
		ft_strcpy(fractal->kernel_name, "spider\0");
	}
	else if (fractal->fractal_type == branches)
	{
		ft_strcpy(fractal->file_name, "kernels/branches_kernel.cl\0");
		ft_strcpy(fractal->win_name, "Branches\0");
		ft_strcpy(fractal->kernel_name, "branches\0");
	}
}

void		names_init(t_fractal *fractal)
{
	if (fractal->fractal_type == mandelbrot)
	{
		ft_strcpy(fractal->file_name, "kernels/mandelbrot_kernel.cl\0");
		ft_strcpy(fractal->win_name, "Mandelbrot\0");
		ft_strcpy(fractal->kernel_name, "mandelbrot\0");
	}
	else if (fractal->fractal_type == julia)
	{
		ft_strcpy(fractal->file_name, "kernels/julia_kernel.cl\0");
		ft_strcpy(fractal->win_name, "Julia\0");
		ft_strcpy(fractal->kernel_name, "julia\0");
	}
	else if (fractal->fractal_type == irina)
	{
		ft_strcpy(fractal->file_name, "kernels/irina_kernel.cl\0");
		ft_strcpy(fractal->win_name, "Irina\0");
		ft_strcpy(fractal->kernel_name, "irina\0");
	}
	else
	{
		names_init_2(fractal);
	}
}
