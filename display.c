#include "fdf.h"

void		display_menu(t_collection *C)
{
	mlx_string_put(C->mlx.init, C->mlx.win, 35, 25, DISPLAY_COLOR, C->map_name);
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 20, DISPLAY_COLOR, "1      color");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 40, DISPLAY_COLOR, "2      contrast");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 60, DISPLAY_COLOR, "right  move");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 80, DISPLAY_COLOR, "left   move");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 100, DISPLAY_COLOR, "up     move");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 120, DISPLAY_COLOR, "down   move");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 140, DISPLAY_COLOR, "q e    rotate y");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 160, DISPLAY_COLOR, "w s    rotate x");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 180, DISPLAY_COLOR, "a d    rotate z");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 200, DISPLAY_COLOR, "+ -    scale");
	mlx_string_put(C->mlx.init, C->mlx.win, WIDTH - 200, 220, DISPLAY_COLOR, "j k    altitude");

}