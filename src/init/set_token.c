/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:44:27 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/08 15:56:31 by tishihar         ###   ########.fr       */
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

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
