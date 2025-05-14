/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:46:59 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/14 16:44:16 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* ─────────────────── 汎用 3 要素 ─────────────────────────── */
static void	print_rgb3(const char *l, t_rgb3 c)
{ printf("%s: r=%d g=%d b=%d\n", l, c.r, c.g, c.b); }

static void	print_pos3(const char *l, t_pos3 p)
{ printf("%s: x=%f y=%f z=%f\n", l, p.x, p.y, p.z); }

static void	print_vec3(const char *l, t_vec3 v)
{ printf("%s: x=%f y=%f z=%f\n", l, v.x, v.y, v.z); }

/* ─────────────────── アンビエント / カメラ ─────────────────── */
static void	print_amb(const t_amb *a)
{
	printf("=== Ambient ===\n");
	printf("intensity: %f\n", a->intensity);
	print_rgb3("rgb", a->rgb);
}

static void	print_cam(const t_cam *c)
{
	printf("\n=== Camera ===\n");
	print_pos3("pos", c->pos);
	print_vec3("forward", c->forward);
	print_vec3("right",   c->right);
	print_vec3("up",      c->up);
	printf("fov=%f fov_rad=%f aspect=%f\n", c->fov, c->fov_rad, c->aspect);
	printf("half_w=%f half_h=%f\n", c->half_w, c->half_h);
	print_pos3("llc", c->llc);
}

/* ─────────────────── ライト（単方向リスト）──────────────────── */
static void	print_light(const t_light *l, int i)
{
	printf("\n=== Light[%d] ===\n", i);
	print_pos3("pos", l->pos);
	printf("intensity: %f\n", l->intensity);
	print_rgb3("rgb", l->rgb);
}

static void	print_lights(const t_light_node *lst)
{
	int idx = 0;

	for (const t_light_node *cur = lst; cur; cur = cur->next)
		print_light(&cur->value, idx++);
	if (!idx)
		printf("\n=== Light ===\n(no light nodes)\n");
}

/* ─────────────────── オブジェクト群 ────────────────────────── */
static const char	*kind_str(t_obj_kind k)
{
	return (k == OBJ_SPHERE ? "Sphere"
		: k == OBJ_PLANE    ? "Plane"
		:                     "Cylinder");
}

static void	print_sphere(const t_sphere *s)
{
	print_pos3("pos", s->pos);
	printf("diameter=%f\n", s->diameter);
	print_rgb3("rgb", s->rgb);
}

static void	print_plane(const t_plane *p)
{
	print_pos3("pos", p->pos);
	print_vec3("normal", p->vec);
	print_rgb3("rgb", p->rgb);
}

static void	print_cylinder(const t_cylinder *c)
{
	print_pos3("pos", c->pos);
	print_vec3("axis", c->vec);
	printf("diameter=%f height=%f\n", c->diameter, c->height);
	print_rgb3("rgb", c->rgb);
}

static void	print_obj(const t_obj *o, int i)
{
	printf("\n=== Object[%d] – %s ===\n", i, kind_str(o->kind));
	if (o->kind == OBJ_SPHERE)
		print_sphere(&o->data.sp);
	else if (o->kind == OBJ_PLANE)
		print_plane(&o->data.pl);
	else
		print_cylinder(&o->data.cy);
}

static void	print_objs(const t_obj *lst)
{
	int idx = 0;

	for (const t_obj *cur = lst; cur; cur = cur->next)
		print_obj(cur, idx++);
	if (!idx)
		printf("\n=== Object ===\n(no objects)\n");
}

/* ─────────────────── MiniLibX ハンドル ─────────────────────── */
static void	print_mlx(const t_mlx *m)
{
	printf("\n=== MiniLibX ===\n");
	printf("mlx.ptr=%p mlx.win=%p\n", m->ptr, m->win);
	printf("img.ptr=%p addr=%p bpp=%d line_len=%d endian=%d\n",
		   m->img.ptr, m->img.addr,
		   m->img.bpp, m->img.line_len, m->img.endian);
}

/* ─────────────────── 公開エントリ ─────────────────────────── */
void	print_info(const t_info *info)
{
	if (!info)
		return ;
	print_amb(&info->amb);
	print_cam(&info->cam);
	print_lights(info->lights);
	print_objs(info->objs);
	print_mlx(&info->mlx);
}