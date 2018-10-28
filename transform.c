#include "fdf.h"

void	translate(t_vector3f *p, t_vector3f move, int dir)
{
	p->x += (move.x * dir);
	p->y += (move.y * dir);
	p->z += (move.z * dir);
}

void	rot_x(t_vector3f *v, double ang, t_vector3f axis)
{
	double tmp;
	double cos_t;
	double sin_t;


	ang = ang * M_PI / 180.0;
	translate(v, axis, -1);
	sin_t = sin(ang);
	cos_t = cos(ang);
	tmp = v->y;
	v->y = v->y * cos_t - v->z * sin_t;
	v->z = tmp * sin_t + v->z * cos_t;
	translate(v, axis, 1);
}

void	rot_y(t_vector3f *v, double ang, t_vector3f axis)
{
	double tmp;
	double cos_t;
	double sin_t;

	ang = ang * M_PI / 180.0;
	translate(v, axis, -1);
	sin_t = sin(ang);
	cos_t = cos(ang);
	tmp = v->z;
	v->z = v->z * cos_t - v->x * sin_t;
	v->x = tmp * sin_t + v->x * cos_t;
	translate(v, axis, 1);
}

void	rot_z(t_vector3f *v, double ang, t_vector3f axis)
{
	double tmp;
	double cos_t;
	double sin_t;

	ang = ang * M_PI / 180.0;
	translate(v, axis, -1);
	sin_t = sin(ang);
	cos_t = cos(ang);
	tmp = v->x;
	v->x = v->x * cos_t - v->y * sin_t;
	v->y = tmp * sin_t + v->y * cos_t;
	translate(v, axis, 1);
}
