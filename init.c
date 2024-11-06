/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:31:55 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/04 16:31:57 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(int err_no)
{
	if (err_no == 1)
		perror("Failed to establish connection");
	else if (err_no == 2)
		perror("Failed to create window");
	else if (err_no == 3)
		perror("Failed to generate image");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *frac)
{
	frac->escape_value = 4;
	frac->iterations_definition = 42;
	frac->shift_x = 0;
	frac->shift_y = 0;
	frac->zoom = 1;
}

static void	events_init(t_fractal *frac)
{
	mlx_hook(frac->mlx_window, 2, 0, key_handler, frac);
	mlx_hook(frac->mlx_window, 4, 0, mouse_handler, frac);
	mlx_hook(frac->mlx_window, 17, 0, close_handler, frac);
}

void	fractal_init(t_fractal *frac)
{
	frac->mlx_connection = mlx_init();
	if (frac->mlx_connection == NULL)
		malloc_error(1);
	frac->mlx_window = mlx_new_window
		(frac->mlx_connection, HEIGHT, WIDTH, frac->name);
	if (frac->mlx_window == NULL)
	{
		free(frac->mlx_connection);
		malloc_error(2);
	}
	frac->img.img_ptr = mlx_new_image
		(frac->mlx_connection, WIDTH, HEIGHT);
	if (frac->img.img_ptr == NULL)
	{
		mlx_destroy_window(frac->mlx_connection, frac->mlx_window);
		free(frac->mlx_connection);
		malloc_error(3);
	}
	frac->img.pixels_ptr = mlx_get_data_addr
		(frac->img.img_ptr, &frac->img.bpp,
			&frac->img.line_len, &frac->img.endian);
	data_init(frac);
	events_init(frac);
}
