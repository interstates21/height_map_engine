#include "fdf.h"

int		set_movement(int keycode, t_collection *C)
{
	if (keycode == KEY_MOV_LEFT)
		C->transform.mov.x -= MOV_SPEED;
	if (keycode == KEY_MOV_RIGHT)
		C->transform.mov.x += MOV_SPEED;
	if (keycode == KEY_MOV_UP)
		C->transform.mov.y -= MOV_SPEED;
	if (keycode == KEY_MOV_DOWN)
		C->transform.mov.y += MOV_SPEED;
	return (0);
}

int		set_rotation(int keycode, t_collection *C)
{
	if (keycode == KEY_ROT_X_RIGHT)
		C->transform.rot.x += ROT_SPEED;
	if (keycode == KEY_ROT_X_LEFT)
		C->transform.rot.x -= ROT_SPEED;
	if (keycode == KEY_ROT_Y_UP)
		C->transform.rot.y += ROT_SPEED;
	if (keycode == KEY_ROT_Y_DOWN)
		C->transform.rot.y -= ROT_SPEED;
	if (keycode == KEY_ROT_Z_RIGHT)
		C->transform.rot.z += ROT_SPEED;
	if (keycode == KEY_ROT_Z_LEFT)
		C->transform.rot.z -= ROT_SPEED;
	return (0);
}

int		set_zoom_and_depth(int keycode, t_collection *C)
{
	if (keycode == KEY_DEPTH_PLUS)
		C->transform.depth += ALTITUDE_SPEED;
	if (keycode == KEY_DEPTH_MIN)
		C->transform.depth -= ALTITUDE_SPEED;
	if (keycode == KEY_ZOOM_MIN)
		C->transform.zoom -= ZOOM_SPEED;
	if (keycode == KEY_ZOOM_PLUS)
		C->transform.zoom += ZOOM_SPEED;
	C->transform.zoom = CLAMP(C->transform.zoom, MIN_ZOOM, MAX_ZOOM);
	return (0);
}

int		set_color(int keycode, t_collection *C)
{
	if (keycode == KEY_NEXT_COLOR)
		C->color_id = (C->color_id + 1) % 3;
	if (keycode == KEY_COLOR_FADE)
		C->color_fade = 1 + ((C->color_fade + 1) % 120);
	return (0);
}