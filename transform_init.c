/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:33:16 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 15:33:19 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	mandelbrot_init(t_transform *fractal_transform)
{
	fractal_transform->zoom = 0.7;
	fractal_transform->delta_x = -0.2;
	fractal_transform->delta_y = 0;
	fractal_transform->old_x = 0;
	fractal_transform->old_y = 0;
	fractal_transform->middle_mouse_pressed = 0;
	fractal_transform->color = 1804;
	fractal_transform->c_re = -0.7f;
	fractal_transform->c_im = 0.29015f;
	fractal_transform->right_mouse_pressed = 0;
}

void	julia_init(t_transform *fractal_transform)
{
	fractal_transform->zoom = 0.6;
	fractal_transform->delta_x = 0;
	fractal_transform->delta_y = 0;
	fractal_transform->old_x = 0;
	fractal_transform->old_y = 0;
	fractal_transform->middle_mouse_pressed = 0;
	fractal_transform->color = 290;
	fractal_transform->c_re = -0.7f;
	fractal_transform->c_im = 0.29015f;
	fractal_transform->right_mouse_pressed = 0;
}

void	irina_init(t_transform *fractal_transform)
{
	fractal_transform->zoom = 0.6;
	fractal_transform->delta_x = 0;
	fractal_transform->delta_y = 0;
	fractal_transform->old_x = 0;
	fractal_transform->old_y = 0;
	fractal_transform->middle_mouse_pressed = 0;
	fractal_transform->color = 0;
	fractal_transform->c_re = -0.45f;
	fractal_transform->c_im = 0.00015f;
	fractal_transform->right_mouse_pressed = 0;
}

void	ship_init(t_transform *fractal_transform)
{
	fractal_transform->zoom = 0.6;
	fractal_transform->delta_x = -0.5;
	fractal_transform->delta_y = -0.5;
	fractal_transform->old_x = 0;
	fractal_transform->old_y = 0;
	fractal_transform->middle_mouse_pressed = 0;
	fractal_transform->color = 940;
	fractal_transform->c_re = 0.167366;
	fractal_transform->c_im = 0.689801;
	fractal_transform->right_mouse_pressed = 0;
}

void	spider_init(t_transform *fractal_transform)
{
	fractal_transform->zoom = 0.7;
	fractal_transform->delta_x = -0.5;
	fractal_transform->delta_y = 0;
	fractal_transform->old_x = 0;
	fractal_transform->old_y = 0;
	fractal_transform->middle_mouse_pressed = 0;
	fractal_transform->color = 118;
	fractal_transform->c_re = -0.7f;
	fractal_transform->c_im = 0.29015f;
	fractal_transform->right_mouse_pressed = 0;
}
