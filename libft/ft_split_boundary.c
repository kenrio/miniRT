/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_boundary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:34:34 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/27 17:05:30 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_element(const char *str, int (*is_boundary)(int));
static int		grow_array(char *str, char **array, int (*is_boundary)(int));
static void		destroy_all(char **origin, char **curr);

// this func() can split string by is_boundary()
char	**ft_boundary_split(char const *str, int (*is_boundary)(int))
{
	size_t	count;
	char	**array;

	if (!str || !is_boundary)
		return (NULL);
	count = count_element(str, is_boundary);
	array = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	if (grow_array((char *)str, array, is_boundary))
		return (NULL);
	return (array);
}

static	size_t	count_element(const char *str, int (*is_boundary)(int))
{
	size_t	count;

	count = 1;
	while (*str)
	{
		if (is_boundary(*str))
			count++;
		str++;
	}
	return (count);
}

static	void	destroy_all(char **origin, char **curr)
{
	while (origin <= curr)
	{
		free(*curr);
		curr--;
	}
	free(origin);
}

static	int	grow_array(char *str, char **array, int (*is_boundary)(int))
{
	char	*token_start;
	char	**origin;

	origin = array;
	while (*str)
	{
		token_start = str;
		if (is_boundary(*str))
			str++;
		while (*str && !is_boundary(*str))
			str++;
		*array = ft_substr(token_start, 0, str - token_start);
		if (!(*array))
		{
			destroy_all(origin, array);
			return (1);
		}
		array++;
	}
	return (0);
}
