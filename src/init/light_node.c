/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:43:31 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/12 18:01:39 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light_node	*new_light_node(t_pos3 pos, double intensity, t_rgb3 rgb)
{
	t_light_node	*node;

	node = (t_light_node *)ft_calloc(1, sizeof(t_light_node));
	if (!node)
		return (NULL);
	node->value.pos = pos;
	node->value.intensity = intensity;
	node->value.rgb = rgb;
	node->next = NULL;
	return (node);
}

void	clean_light_nodes(t_light_node *head_node)
{
	t_light_node	*curr;
	t_light_node	*next;

	curr = head_node;
	while (!curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}
