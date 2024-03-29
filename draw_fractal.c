/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:33:39 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 15:38:34 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	initiate_kernel(t_fractal *fractal)
{
	size_t		global_work_size;

	fractal->ret = clEnqueueWriteBuffer(fractal->command_queue,
			fractal->utils_memobj, CL_TRUE, 0,
			sizeof(t_transform),
			&fractal->transform, 0, NULL, NULL);
	fractal->ret = clSetKernelArg(fractal->kernel, 1,
			sizeof(cl_mem), (void *)&fractal->utils_memobj);
	global_work_size = WIDTH * WIDTH;
	fractal->ret = clEnqueueNDRangeKernel(fractal->command_queue,
			fractal->kernel, 1, NULL, &global_work_size,
			NULL, 0, NULL, NULL);
	fractal->ret = clEnqueueReadBuffer(fractal->command_queue,
			fractal->memobj, CL_TRUE, 0,
			WIDTH * WIDTH * 4, fractal->image_data, 0, NULL, NULL);
}

void		draw_fractal(t_fractal *fractal)
{
	static int	windows_count;

	if (!fractal->win_ptr)
	{
		transform_init(fractal);
		fractal_init(fractal);
		windows_count++;
	}
	initiate_kernel(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
			fractal->image, 0, 0);
	draw_guide(fractal);
	mlx_hook(fractal->win_ptr, 2, 1L << 0, key_pressed, fractal);
	mlx_hook(fractal->win_ptr, 4, 1L << 0, mouse_press, fractal);
	mlx_hook(fractal->win_ptr, 5, 1L << 0, mouse_release, fractal);
	mlx_hook(fractal->win_ptr, 6, 1L << 0, mouse_move, fractal);
	mlx_hook(fractal->win_ptr, 17, 1L << 0, close_window, &windows_count);
}
