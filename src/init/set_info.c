/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:25:34 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/08 15:27:13 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool is_space(char c);
static t_elem get_elem_type(char *s);

bool	set_info(t_info *info, char *file_name)
{
	int		file_fd;
	char	*line;
	t_elem	type;

	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (false);
	line = get_next_line(file_fd);
	if (!line)
		return (close(file_fd), false);
	while (line)
	{
		type = get_elem_type(line);
		
		if (type == E_AMBIENT)
			set_amb(info, line);
		else if (type == E_CAMERA)
			set_cam(info, line);
		else if (type == E_LIGHT)
			set_light(info, line);

		// 個々からは未対応	
		// else if (type == E_SPHERE)
		// 	set_sphere(info, line);
		// else if (type == E_PLANE)
		// 	set_plane(info, line);
		// else if (type == E_CYLINDER)
		// 	set_cylinder(info, line);
		else if (type == E_INVALID)
		{
			perror("find invalid element type.");
			return (free(line) ,close(file_fd), false);
		}
		free(line);
		line = get_next_line(file_fd);
	}
	close(file_fd);
	return (true);
}

static bool is_space(char c)
{
    return (c == ' ' || c == '\t');
}

static t_elem get_elem_type(char *s)
{
	while (is_space(*s))
		++s;
	if (*s == 'A' && is_space(s[1]))
		return E_AMBIENT;
	if (*s == 'C' && is_space(s[1]))
		return E_CAMERA;
	if (*s == 'L' && is_space(s[1]))
		return E_LIGHT;
	if (*s == 's' && s[1] == 'p' && is_space(s[2]))
		return E_SPHERE;
	if (*s == 'p' && s[1] == 'l' && is_space(s[2]))
		return E_PLANE;
	if (*s == 'c' && s[1] == 'y' && is_space(s[2]))
		return E_CYLINDER;
	return E_INVALID;
}
