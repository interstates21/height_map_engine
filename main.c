#include "fdf.h"

static int 	check_map_name(char *arg)
{
	int		check_file_len;
	int		fd;
	char	*buff[MIN_MAP_SIZE << 1];

	if ((fd = open(arg, O_RDONLY)) < 0)
		return (0);
	check_file_len = read(fd, buff, MIN_MAP_SIZE << 1);
	if (check_file_len < MIN_MAP_SIZE)
		return (0);
	return (1);
}

static int		set_defaults(t_collection *C)
{
	// GET AN AMPTY IMAGE STRING REFERENCE FOR WRITING PIXELS
	// AND EXTRA IMG INFORMATION
	if (!(C->mlx.img_string = mlx_get_data_addr(C->mlx.img,
	&C->mlx.bpp, &C->mlx.line_size, &C->mlx.endian)))
		return (0);
	C->transform.rot = new_vec3f(0, 0, 0);
	C->transform.zoom = WIDTH / 2 / C->map_len.x;
	C->transform.mov = new_vec3f(C->map_len.x / 2 * C->transform.zoom,
	C->map_len.y / 2 * C->transform.zoom, 0);
	C->transform.depth = 0.035;
	C->color_id = 0;
	C->min_z = INFINITY;
	C->max_z = 0;
	C->color_fade = 30;
	render_this_frame(C);
	mlx_put_image_to_window(C->mlx.init, C->mlx.win, C->mlx.img, 0, 0);
	display_menu(C);
	return (1);
}

int		listen_keys_and_render_frame(int keycode, t_collection *C)
{
	if (keycode == KEY_EXIT)
		listen_exit();
	set_movement(keycode, C);
	set_rotation(keycode, C);
	set_zoom_and_depth(keycode, C);
	set_color(keycode, C);
	ft_bzero(C->mlx.img_string, (WIDTH * HEIGHT * 4));
	mlx_clear_window(C->mlx.init, C->mlx.win);
	render_this_frame(C);
	mlx_put_image_to_window(C->mlx.init, C->mlx.win, C->mlx.img, 0, 0);
	display_menu(C);
	return (0);
}

// void	print_map(t_collection *C)
// {
// 	for (int i = 0; i < C->map_len.y; i++)
// 	{
// 		for (int j = 0; j < C->map_len.x; j++)
// 		{
// 			ft_putnbr(C->points[i][j].z);
// 			ft_putchar(' ');
// 		}
// 		ft_putchar('\n');
// 	}
// }

int 	main(int argc, char **argv)
{
	t_collection C;
	if (argc != 2)
		return (print_error(0));
	if (!check_map_name(argv[1]))
		return (print_error(1));
	C.map_name = argv[1];
	// INIT FOR A GRAPHICS LIB
	if (!(C.mlx.init = mlx_init()))
		return (print_error(2));
	if (!(C.mlx.win = mlx_new_window(C.mlx.init, WIDTH, HEIGHT, WIN_NAME)))
		return (print_error(2));
	if (!(C.mlx.img = mlx_new_image(C.mlx.init, WIDTH, HEIGHT)))
		return (print_error(2));
	if (!parse_manager(&C))
	 	return (0);
	// print_map(&C);
	// LOOP THE WINDOW AND ANIMATE
	if (!set_defaults(&C))
		return (print_error(2));
	mlx_hook(C.mlx.win, HOOK_PRESS_KEY, HOOK_RESET_KEY, listen_keys_and_render_frame, &C); // READS INPUT AND REDRAWS A FRAME EACH TIME YOU PRESS A KEY
	mlx_hook(C.mlx.win, HOOK_RED_CROSS_IN, HOOK_RED_CROSS_OUT, listen_exit, &C); // READS INPUT AND CHECKS IF WE'VE PRESSED THE CLOSING CROSS
	mlx_loop(C.mlx.init);
}