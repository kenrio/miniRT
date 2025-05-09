/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:25:34 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/09 19:46:50 by tishihar         ###   ########.fr       */
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
		return (perror("file cannot open."), false);
	line = get_next_line(file_fd);
	if (!line)
		return (perror("read line failed."), close(file_fd), false);
	while (line)
	{
		type = get_elem_type(line);
		if (type != E_SPACE)
		{
			if (type == E_AMBIENT)
				set_amb(info, line);
			else if (type == E_CAMERA)
				set_cam(info, line);
			else if (type == E_LIGHT)
				set_light(info, line);
			else if (type == E_INVALID)
			{
				perror("find invalid element type.");
				info->is_init_success = false;
			}
		}
		free(line);
		line = get_next_line(file_fd);
	}
	close(file_fd);

	// check
	if (info->is_init_success == false)
	{
		perror("initialization info failed...");
		return (false);
	}
	return (true);
}

// 個々からは未対応	
		// else if (type == E_SPHERE)
		// 	set_sphere(info, line);
		// else if (type == E_PLANE)
		// 	set_plane(info, line);
		// else if (type == E_CYLINDER)
		// 	set_cylinder(info, line);

static bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static t_elem get_elem_type(char *s)
{
	while (is_space(*s))
		++s;
	if (*s == '\n')
		return (E_SPACE);
	if (*s == 'A' && is_space(s[1]))
		return (E_AMBIENT);
	if (*s == 'C' && is_space(s[1]))
		return (E_CAMERA);
	if (*s == 'L' && is_space(s[1]))
		return (E_LIGHT);
	if (*s == 's' && s[1] == 'p' && is_space(s[2]))
		return (E_SPHERE);
	if (*s == 'p' && s[1] == 'l' && is_space(s[2]))
		return (E_PLANE);
	if (*s == 'c' && s[1] == 'y' && is_space(s[2]))
		return (E_CYLINDER);
	return E_INVALID;
}
