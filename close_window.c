/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:02:40 by chorange          #+#    #+#             */
/*   Updated: 2019/03/14 16:20:35 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	close_window(void *param)
{
	int *windows_count;

	windows_count = (int *)param;
	if (*windows_count == 1)
		exit(1);
	(*windows_count)--;
	return (0);
}
