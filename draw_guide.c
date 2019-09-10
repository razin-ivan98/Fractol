/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_guide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:37:00 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 16:18:39 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	put_string(t_fractal *fractal, int x, int y, char *string)
{
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, x, y, 0xFFFFFF, string);
}

void		draw_info(t_fractal *fractal)
{
	put_string(fractal, 40, 960, "Iterations count:");
	put_string(fractal, 220, 960, ft_itoa(fractal->transform.max_iterations));
}

void		draw_guide(t_fractal *fractal)
{
	if (!fractal->transform.guide_visible)
		put_string(fractal, 40, 20, "Press H to show Info & Guide");
	else
	{
		put_string(fractal, 40, 20, "Fractol");
		put_string(fractal, 40, 40, "Type:");
		put_string(fractal, 100, 40, fractal->win_name);
		put_string(fractal, 40, 80, "Guide:");
		put_string(fractal, 40, 100,
"Use ARROWS or MIDDLE MOUSE BUTTON to move image");
		put_string(fractal, 40, 120, "Use +/- or MOUSE WHEEL to change scale");
		put_string(fractal, 40, 140, "Press 1 or 2 to change iterations count");
		put_string(fractal, 40, 160, "Press C to change color");
		put_string(fractal, 40, 180,
"Use RIGHT MOUSE BUTTON to change constants");
		put_string(fractal, 40, 200, "	for Julia and Irina fractals");
		put_string(fractal, 40, 220, "Press D to set default parameters");
		put_string(fractal, 40, 240, "Press ESC to exit");
		put_string(fractal, 40, 260, "Press H to hide Info & Guide");
	}
	draw_info(fractal);
}
