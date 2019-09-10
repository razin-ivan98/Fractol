/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_init_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:33:10 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 15:33:13 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	branches_init(t_transform *fractal_transform)
{
	fractal_transform->zoom = 0.6;
	fractal_transform->delta_x = 0;
	fractal_transform->delta_y = 0;
	fractal_transform->old_x = 0;
	fractal_transform->old_y = 0;
	fractal_transform->middle_mouse_pressed = 0;
	fractal_transform->color = 572;
	fractal_transform->c_re = -0.7f;
	fractal_transform->c_im = 0.29015f;
	fractal_transform->right_mouse_pressed = 0;
}
