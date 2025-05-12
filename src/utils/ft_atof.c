/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:14:53 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/09 19:17:49 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minirt.h"

static int	ft_isspace(int c);

// this func not support exp.
// support format: [-]123.45;
double	ft_atof(char *str)
{
	int					sign;
	long	double		val;
	long	double		frac_scale;
	long	double		result;

	while (ft_isspace(*str))
		str++;
	sign = -2 * (*str == '-') + 1;
	str += (*str == '-' ||  *str == '+');
	val = 0.0;
	while (ft_isdigit(*str))
		val = 10.0 * val + (*(str++) - '0');
	frac_scale = 1.0;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			val = 10 * val + (*str - '0');
			frac_scale *= 10.0;
			str++;
		}
	}
	result = sign * (val / frac_scale);
	return ((double)result);
}

static int	ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
