/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:44:27 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/08 21:16:10 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	validate_token(char *elem);
static int 	ft_isspace(char c);
static bool is_valid_token(char c);

// tokenize part.
// if invalid token, return NULL;
char	*get_valid_token(char *elem, int idx)
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
	if (validate_token(elem) == false)
	{
		perror("invalid input.");
		return (NULL);
	}
	return (elem);
}

bool is_valid_start(char c)
{
	return (c == '+' || c == '-' || ft_isdigit(c));
}

static bool	validate_token(char *elem)
{
	if (!elem)
		return (false);
	if (is_valid_start(*elem) == false)
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
