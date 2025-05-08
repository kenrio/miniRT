/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:44:27 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/08 16:23:45 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int ft_isspace(char c);

// tokenize part.
char	*get_token(char *elem, int idx)
{
	if (!elem || idx < 0)
		return (NULL);
	while (ft_isspace(*elem))
		elem++;
	while (*elem && idx > 0)
	{
		while (*elem && !ft_isspace(*elem))
			elem++;
		while (ft_isspace(*elem))
			elem++;
		idx--;
	}
	if (*elem == '\0')
		return (NULL);
	return (elem);
}

//   次の空白までの間に有効文字以外が入ってこないか
bool	validate_token(char *elem)
{
	if (!elem)
		return (false);
	while (*elem && !ft_isspace(*elem))
	{
		if (is_valid_token(*elem) == false)
			return (false);
		elem++;
	}
	return (true);
}

static bool is_valid_token(char c)
{
	return (c == '+' || c == '-' || ft_isdigit(c) || c == '.' || c == ',');
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
