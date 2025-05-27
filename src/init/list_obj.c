/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:12:57 by anya_stella       #+#    #+#             */
/*   Updated: 2025/05/23 13:25:15 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// how to use:
// objs = add_objs_front(info->objs, create_sp())...
t_obj	*add_obj_front(t_obj *head, t_obj *new)
{
	if (!new)
		return (NULL);
	new->next = head;
	return (new);
}

void	clean_obj_nodes(t_obj *head)
{
	t_obj	*curr;
	t_obj	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

t_obj	*new_obj_sp(t_sphere sp, t_mat mat)
{
	t_obj	*node;

	node = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!node)
		return (NULL);
	node ->kind = OBJ_SPHERE;
	node->data.sp = sp;
	node->mat = mat;
	node->next = NULL;
	return (node);
}

t_obj	*new_obj_pl(t_plane pl, t_mat mat)
{
	t_obj	*node;

	node = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!node)
		return (NULL);
	node ->kind = OBJ_PLANE;
	node->data.pl = pl;
	node->mat = mat;
	node->next = NULL;
	return (node);
}

t_obj	*new_obj_cy(t_cylinder cy, t_mat mat)
{
	t_obj	*node;

	node = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!node)
		return (NULL);
	node ->kind = OBJ_CYLINDER;
	node->data.cy = cy;
	node->mat = mat;
	node->next = NULL;
	return (node);
}
