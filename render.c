#include "fdf.h"

static	t_rgb apply_hex(t_vector3 p1, t_vector3 p2)
{
	t_rgb		rgb1;
	t_rgb		rgb2;

	rgb1 = ui_to_rgb(p1.hex_col);
	rgb2 = ui_to_rgb(p2.hex_col);
	return (mix_rgb(rgb1, rgb2));
}

static	t_rgb apply_color(int color_id, int altitude, int fade)
{
	t_rgb	rgb;

	if (color_id == 0)
		rgb = new_rgb(altitude * fade / 5, altitude * fade / 5, altitude * fade / 5);
	if (color_id == 1)
		rgb = new_rgb(altitude * fade / 4, 50, 50);
	if (color_id == 2)
		rgb = new_rgb(20, 00, altitude * fade / 2);
	return (rgb);
}

static 	void	linear_transform(t_vector3f *p, t_transform transform, t_vector2 rot_axis)
{
	p->x -= rot_axis.x;
	p->y -= rot_axis.y;
	p->z *= transform.depth;
	rot_y(p, transform.rot.y);
	rot_z(p, transform.rot.z);
	rot_x(p, transform.rot.x);
	p->x *= transform.zoom;
	p->y *= transform.zoom;
	p->x += rot_axis.x;
	p->y += rot_axis.y;
	p->x += transform.mov.x;
	p->y += transform.mov.y;
}

static	void	render_horizontal(t_collection *C, int j, int i)
{
	t_vector3f p1;
	t_vector3f p2;
	t_vector2	proj_p1;
	t_vector2	proj_p2;
	t_rgb		rgb;

	p1 = new_vec3f(C->points[j][i].x, C->points[j][i].y, C->points[j][i].z);
	p2 = new_vec3f(C->points[j][i + 1].x, C->points[j][i + 1].y, C->points[j][i + 1].z);
	if (!C->points[j][i].hex_col && !C->points[j][i + 1].hex_col)
		rgb = apply_color(C->color_id, (p2.z + p1.z) / 2, C->color_fade);
	else
		rgb = apply_hex(C->points[j][i], C->points[j][i + 1]);
	linear_transform(&p1, C->transform, v2_scale(C->map_len, 0.5));
	linear_transform(&p2, C->transform, v2_scale(C->map_len, 0.5));
	proj_p1 = new_vec3f_projection(p1);
	proj_p2 = new_vec3f_projection(p2);
	line(C, proj_p1, proj_p2, rgb);
}

static	void	render_vertical(t_collection *C, int j, int i)
{
	t_vector3f p1;
	t_vector3f p2;
	t_vector2	proj_p1;
	t_vector2	proj_p2;
	t_rgb		rgb;

	p1 = new_vec3f(C->points[j][i].x, C->points[j][i].y, C->points[j][i].z);
	p2 = new_vec3f(C->points[j + 1][i].x, C->points[j + 1][i].y, C->points[j + 1][i].z);
	if (!C->points[j][i].hex_col &&!C->points[j + 1][i].hex_col)
		rgb = apply_color(C->color_id, (p2.z + p1.z) / 2, C->color_fade);
	else
		rgb = apply_hex(C->points[j][i], C->points[j + 1][i]);
	linear_transform(&p1, C->transform, v2_scale(C->map_len, 0.5));
	linear_transform(&p2, C->transform, v2_scale(C->map_len, 0.5));
	proj_p1 = new_vec3f_projection(p1);
	proj_p2 = new_vec3f_projection(p2);
	line(C, proj_p1, proj_p2, rgb);
}

void			render_this_frame(t_collection *C)
{
	int i;
	int j;

	j = 0;
	while (j < C->map_len.y)
	{
		i = 0;
		while (i < C->map_len.x)
		{
			if (i < C->map_len.x - 1) // ON THE HORIZONTAL EDGE WE RENDER ONLY VERTICAL LINE
				render_horizontal(C, j, i);
			if (j < C->map_len.y - 1) // ON THE VERTICAL EDGE WE RENDER ONLY HORIZONTAL LINE
				render_vertical(C, j, i);
			i++;
		}
		j++;
	}
}