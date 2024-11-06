/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:32:52 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/04 16:32:53 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (n <= 0 || s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && i < n - 1)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 == c2)
			i++;
		else
			return (c1 - c2);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i += 1;
	}
}

void	skip_whitespace(char **str)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
}

double	parse_integer_part(char **str)
{
	double	result;

	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		result = (result * 10) + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	parse_decimal_part(char **str)
{
	double	decimal;
	int		count;

	decimal = 0;
	count = 0;
	if (**str == '.')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		decimal = (decimal * 10) + (**str - '0');
		count++;
		(*str)++;
	}
	return (decimal / pow(10, count));
}
