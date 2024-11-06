/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:32:18 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/04 16:32:19 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	char		*error_msg;

	error_msg = ERROR_MESSAGE_1 ERROR_MESSAGE_2;
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		fractal.julia_x = atodbl(argv[2]);
		fractal.julia_y = atodbl(argv[3]);
		fractal_init(&fractal);
		fractal_render(&fractal);
	}
	else
	{
		ft_putstr_fd(error_msg, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
