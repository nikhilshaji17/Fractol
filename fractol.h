/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:32:35 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/04 16:32:37 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h> // only for perror
# include "mlx/mlx.h"

# define ERROR_MESSAGE_1 "Please enter the input as: \n./fractol mandelbrot"
# define ERROR_MESSAGE_2 "\n or \n./fractol julia <value_1> <value_2>"
# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define ORANGE 0xFF8000
# define PURPLE 0x800080
# define GREEN 0x00FF00

# define MAGENTA 0xFF00FF
# define CYAN 0x00FFFF
# define BRIGHT_BLUE 0x0080FF
# define DEEP_PINK 0xFF1493
# define INDIGO 0x4B0082
# define HOT_PINK 0xFF69B4
# define PSYCHEDELIC_PURPLE 0xA020F0
# define AQUA_BLUE 0x00FFFF
# define LAVA_RED 0xFF4500 

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;

	void	*mlx_connection;
	void	*mlx_window;

	t_img	img;

	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		iterations_definition;

}	t_fractal;

double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z1);
int			handle_sign(char **str);
double		atodbl(char *str);

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		skip_whitespace(char **str);
double		parse_integer_part(char **str);
double		parse_decimal_part(char **str);

void		ft_putchar(char c, int *num_printed);
void		ft_putstr(char *s, int *num_printed);
void		ft_putnbr(int n, int *num_printed);
void		ft_putunbr(unsigned int n, int *num_printed);
void		ft_puthex(unsigned long long n, char c, int *num_printed);
int			ft_printf(const char *format, ...);

#endif
