#include "fdf.h"

static	void		draw_horizontal_line(t_collection *C, t_vector2 p1, t_rgb rgb)
{
	// SAVE VAR IN CPU FOR A HIGHER PERFORMANCE
	register int float_to_int_error;
	register int x;
	register int y;
	register int i;

	float_to_int_error = (C->brasen.delta.y << 1) - C->brasen.delta.x;

	// THE FIRST PIXEL
	x = p1.x + C->brasen.dir.x;
	y = p1.y;
	i = 1;
	put_pixel_to_img(C, p1, rgb);
	//

	while (i <= C->brasen.delta.x)
	{
		if (float_to_int_error > 0) // IF A FLOAT LINE IS CLOSER TO THE NEXT VERTICAL SQUARE THAN TO THIS
		{
			float_to_int_error += (C->brasen.delta.y - C->brasen.delta.x) << 1;
			y += C->brasen.dir.y; // MOVE TO ANOTHER SQUARE
		}
		else
			float_to_int_error += C->brasen.delta.y << 1; // STAY ON THE SAME VERTICAL SQUARE
		put_pixel_to_img(C, new_vec2(x, y), rgb);
		i++;
		x += C->brasen.dir.x; // X MOVES EACH FRAME WITHOUT CALCULATIONS
	}
}

static	void		draw_vertical_line(t_collection *C, t_vector2 p1, t_rgb rgb)
{
	register int float_to_int_error;
	register int i;
	register int x;
	register int y;

	float_to_int_error = (C->brasen.delta.x << 1) - C->brasen.delta.y;
	y = p1.y + C->brasen.dir.y;
	x = p1.x;
	i = 1;
	put_pixel_to_img(C, p1, rgb);
	while (i <= C->brasen.delta.y)
	{
		if (float_to_int_error > 0)
		{
			float_to_int_error += (C->brasen.delta.x - C->brasen.delta.y) << 1;
			x += C->brasen.dir.x;
		}
		else
			float_to_int_error += C->brasen.delta.x << 1;
		put_pixel_to_img(C, new_vec2(x, y), rgb);
		i++;
		y += C->brasen.dir.y;
	}
}

void			line(t_collection *C, t_vector2 p1, t_vector2 p2, t_rgb rgb)
{
	// CALCULATE LINE'S INCLINATION
	C->brasen.delta.x = abs(p2.x - p1.x);
	C->brasen.delta.y = abs(p2.y - p1.y);
	// CALCULATE LINE'S DIRECTION (SOLVES IF P1 AND P2 ARE SWAPPED)
	C->brasen.dir.x = p2.x >= p1.x ? 1 : -1;
	C->brasen.dir.y = p2.y >= p1.y ? 1 : -1;
	if (C->brasen.delta.x > C->brasen.delta.y)
		draw_horizontal_line(C, p1, rgb); // X IS CONSTANT, CALCULATE Y
	else
		draw_vertical_line(C, p1, rgb); // Y IS CONSTANT, CALCULATE X
}