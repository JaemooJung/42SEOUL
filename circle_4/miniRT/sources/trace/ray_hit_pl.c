/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_pl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:12:55 by jaemjung          #+#    #+#             */
/*   Updated: 2022/07/05 22:18:37 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	hit_plane(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	float	numrator;
	float	denominator;
	float	root;

	pl = obj->element;
	denominator = vdot(ray->dir, pl->dir);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	numrator = vdot(vminus(pl->center, ray->orig), pl->dir);
	root = numrator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	if (pl->radius != INFINITY)
		if (vlength(vminus(pl->center, rec->p)) > pl->radius)
			return (FALSE);
	rec->normal = pl->dir;
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (TRUE);
}
