/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:26:32 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 15:42:00 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include <unistd.h>
# include <OpenCL/opencl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define WIDTH 1024

typedef enum		e_fractal_type
{
	julia,
	mandelbrot,
	irina,
	ship,
	spider,
	branches,
}					t_fractal_type;

typedef struct		s_transform
{

	double			zoom;
	double			delta_y;
	double			delta_x;
	double			c_re;
	double			c_im;
	unsigned int	color;
	unsigned int	max_iterations;
	int				middle_mouse_pressed;
	int				right_mouse_pressed;
	int				old_x;
	int				old_y;
	int				guide_visible;
}					t_transform;

typedef struct		s_fractal
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*image;
	char				*image_data;

	t_fractal_type		fractal_type;

	t_transform			transform;

	cl_int				ret;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;

	cl_device_id		device_id;
	cl_uint				ret_num_devices;

	cl_context			context;
	cl_command_queue	command_queue;

	cl_program			program;
	cl_kernel			kernel;

	char				file_name[40];
	char				win_name[40];
	char				kernel_name[40];

	size_t				source_size;
	char				*source_str;
	cl_mem				memobj;

	cl_mem				utils_memobj;
}					t_fractal;

void				arguments_check(int argc, char **argv);

int					cl_source_str_gen(char *file_name, char **source_str);

void				draw_fractal(t_fractal *fractal);

void				transform_init(t_fractal *fractal);

void				mandelbrot_init(t_transform *fractal_transform);
void				julia_init(t_transform *fractal_transform);
void				irina_init(t_transform *fractal_transform);
void				ship_init(t_transform *fractal_transform);
void				spider_init(t_transform *fractal_transform);
void				branches_init(t_transform *fractal_transform);

void				fractal_init(t_fractal *fractal);
void				names_init(t_fractal *fractal);

int					mouse_press(int button, int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);
int					key_pressed(int key, void *param);

void				zoom_plus(t_fractal *fractal, int dx, int dy);
void				zoom_minus(t_fractal *fractal, int dx, int dy);
void				move(t_fractal *fractal, int dx, int dy);
void				change_consts(t_fractal *fractal, int dx, int dy);

void				draw_guide(t_fractal *fractal);

int					close_window(void *param);

#endif
