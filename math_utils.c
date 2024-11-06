/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:32:43 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/04 16:32:45 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

t_complex	square_complex(t_complex z1)
{
	t_complex	result;

	result.real = (z1.real * z1.real) - (z1.imaginary * z1.imaginary);
	result.imaginary = (2 * z1.real * z1.imaginary);
	return (result);
}

int	handle_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

double	atodbl(char *str)
{
	double	result;
	double	decimal;
	int		sign;

	skip_whitespace(&str);
	sign = handle_sign(&str);
	result = parse_integer_part(&str);
	decimal = parse_decimal_part(&str);
	return ((result + decimal) * sign);
}
