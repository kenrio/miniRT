/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:16:37 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/19 12:30:10 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool		is_space(char c);
static t_elem	get_elem_type(char *s);
static void		dispatch_init(char *line, t_info *info);

bool	init_elements(t_info *info, char *file_name)
{
	int		file_fd;
	char	*line;

	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (perror("file cannot open."), false);
	line = get_next_line(file_fd);
	if (!line)
		return (perror("read line failed."), close(file_fd), false);
	while (line)
	{
		dispatch_init(line, info);
		free(line);
		line = get_next_line(file_fd);
	}
	close(file_fd);
	if (info->is_init_success == false)
		return (perror("initialization info failed..."), false);
	return (true);
}

static void	dispatch_init(char *line, t_info *info)
{
	t_elem	type;

	type = get_elem_type(line);
	if (type != E_SPACE)
	{
		if (type == E_AMBIENT)
			init_amb(info, line);
		else if (type == E_CAMERA)
			init_cam(info, line);
		else if (type == E_LIGHT)
			init_lights(info, line);
		else if (type == E_SPHERE)
			init_objs(info, line, E_SPHERE);
		else if (type == E_PLANE)
			init_objs(info, line, E_PLANE);
		else if (type == E_CYLINDER)
			init_objs(info, line, E_CYLINDER);
		else if (type == E_INVALID)
		{
			perror("find invalid element type.");
			info->is_init_success = false;
		}
	}
}

static bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static t_elem	get_elem_type(char *s)
{
	while (is_space(*s))
		++s;
	if (*s == '\n' || *s == '#')
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
	return (E_INVALID);
}
