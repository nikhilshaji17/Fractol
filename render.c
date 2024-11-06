/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:32:24 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/04 16:32:25 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * ((img->bpp) / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->imaginary = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.imaginary = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	i = 0;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (((z.real * z.real) + (z.imaginary * z.imaginary))
			> fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, BLACK);
			return ;
		}
		i += 1;
	}
	my_pixel_put(x, y, &fractal->img, (WHITE * fractal->zoom));
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
	mlx_loop(fractal->mlx_connection);
}
