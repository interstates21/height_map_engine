#include "fdf.h"

t_rgb		ui_to_rgb(unsigned int i)
{
	t_rgb rgb;

	rgb.blue = i & 255;
	rgb.green = (i >> 8) & 255;
	rgb.red = (i >> 16) & 255;
	return (rgb);
}

t_vector3f	v3f_scale(t_vector3f v, double scaler)
{
	t_vector3f result;

	result.x = v.x * scaler;
	result.y = v.y * scaler;
	result.z = v.z * scaler;

	return (result);
}

t_vector2	new_vec2(int x, int y)
{
	t_vector2 v;
	v.x = x;
	v.y = y;

	return (v);
}

t_vector3f	new_vec3f(double x, double y, double z)
{
	t_vector3f v;

	v.x = x;
	v.y = y;
	v.z = z;

	return (v);
}

t_vector2	new_vec3f_projection(t_vector3f a)
{
	t_vector2 b;

	b.x = (int)a.x;
	b.y = (int)a.y;

	return (b);
}

t_rgb		new_rgb(int red, int green, int blue)
{
	t_rgb col;

	red = CLAMP(red, 25, 250);
	blue = CLAMP(blue, 25, 250);
	green = CLAMP(green, 25, 250);
	col.red = red;
	col.blue = blue;
	col.green = green;

	return (col);
}

t_rgb		mix_rgb(t_rgb r1, t_rgb r2)
{
	t_rgb rgb;

	rgb.red = (r1.red + r2.red) / 2;
	rgb.blue = (r1.blue + r2.blue) / 2;
	rgb.green = (r1.green + r2.green) / 2;

	return (rgb);
}

void		put_pixel_to_img(t_collection *C, t_vector2 p, t_rgb rgb)
{
	if (p.x < LIMIT_PIXEL_WIN_EDGE || p.x > WIDTH - LIMIT_PIXEL_WIN_EDGE - 1
	|| p.y < LIMIT_PIXEL_WIN_EDGE || p.y > HEIGHT - LIMIT_PIXEL_WIN_EDGE - 1)
		return ;
	C->mlx.img_string[(p.x * 4) + (p.y * 4 * WIDTH)] = rgb.blue;
	C->mlx.img_string[(p.x * 4) + (p.y * 4 * WIDTH) + 1] = rgb.green;
	C->mlx.img_string[(p.x * 4) + (p.y * 4 * WIDTH) + 2] = rgb.red;
	//NO NEED FOR ALPHA
}
