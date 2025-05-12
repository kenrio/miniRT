/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:47:12 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/09 20:13:14 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 有効文字は符号、数字、カンマ、小数点のみ
// 現状、,,,.,.0.8とかそのまま入力されるので　０として解釈されそう

// double_set
// スペースか塗る終端が終わりなことに注意
double	parse_double(char *token)
{
	if (!token)
		return (0.0);
	return (ft_atof(token));
}

// 255, shn255, 255
int	parse_3int(char *token, int idx)
{
	if (!token)
		return (0);
	while (*token && idx > 0)
	{
		while (*token && !(*token == ','))
			token++;
		while (*token == ',')
			token++;
		idx--;
	}
	if (is_valid_start(*token) == false)
	{
		perror("invalid input. 3 integer demand.");
		return (0);
	}
	return (ft_atoi(token));
}

double	parse_3double(char *token, int idx)
{
	if (!token)
		return (0.0);
	while (*token && idx > 0)
	{
		while (*token && !(*token == ','))
			token++;
		while (*token == ',')
			token++;
		idx--;
	}
	if (is_valid_start(*token) == false)
	{
		perror("invalid input. 3 double demand.");
		return (0.0);
	}
	return (ft_atof(token));
}
