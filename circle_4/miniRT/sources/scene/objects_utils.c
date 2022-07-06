/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:09:03 by jaemjung          #+#    #+#             */
/*   Updated: 2022/07/06 13:16:34 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "error.h"
#include "utils.h"
#include "scene.h"

void	attach_cy_cap(t_object **objs, t_object *cy_obj)
{
	t_cylinder	*cy;
	t_plane		*top_cap;
	t_plane		*bot_cap;

	cy = cy_obj->element;
	top_cap = plane(cy->center, cy->dir, cy->radius);
	bot_cap = plane(vplus(cy->center, vmult(cy->dir, cy->height)),
			cy->dir, cy->radius);
	obj_add(objs, object(PL, top_cap, cy_obj->albedo));
	obj_add(objs, object(PL, bot_cap, cy_obj->albedo));
}

void	obj_add(t_object **objects, t_object *new)
{
	t_object	*curr;

	if (*objects == NULL)
	{
		*objects = new;
		if (new->type == CY)
			attach_cy_cap(objects, new);
		return ;
	}
	curr = *objects;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	if (new->type == CY)
		attach_cy_cap(objects, new);
}

t_object	*obj_last(t_object *objects)
{
	if (objects == NULL)
		return (NULL);
	while (objects->next)
		objects = objects->next;
	return (objects);
}
