
#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include "get_next_line.h"

#define WIDTH 1600
#define HEIGHT 800
#define WIN_NAME C.map_name
#define MOV_SPEED 10
#define ROT_SPEED 10
#define ALTITUDE_SPEED 0.01
#define ZOOM_SPEED 1
#define MIN_MAP_SIZE 8
#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#define HOOK_PRESS_KEY 2
#define HOOK_RESET_KEY 5
#define HOOK_RED_CROSS_IN 17
#define HOOK_RED_CROSS_OUT 0

#define KEY_EXIT 53
#define KEY_ROT_Z_LEFT 0
#define KEY_ROT_Z_RIGHT 2
#define KEY_ROT_Y_UP 12
#define KEY_ROT_Y_DOWN 14
#define KEY_ROT_X_RIGHT 1
#define KEY_ROT_X_LEFT 13

#define KEY_MOV_LEFT 123
#define KEY_MOV_RIGHT 124
#define KEY_MOV_UP 126
#define KEY_MOV_DOWN 125
#define KEY_DEPTH_MIN 38
#define	KEY_DEPTH_PLUS 40
#define	KEY_ZOOM_MIN 78
#define	KEY_ZOOM_PLUS 69
#define KEY_NEXT_COLOR 18
#define KEY_COLOR_FADE 19
#define LIMIT_PIXEL_WIN_EDGE 5

#define MIN_ZOOM 0.5
#define MAX_ZOOM 2500
#define MIN_DEPTH -10
#define MAX_DEPTH 10

#define DISPLAY_COLOR 0x663333
typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
}				t_rgb;

typedef struct	s_vector2 {
	int		x;
	int		y;
}				t_vector2;

typedef struct	s_vector3 {
	int		x;
	int		y;
	int		z;
	int		hex_col;
}				t_vector3;

typedef struct	s_vector3f {
	double	x;
	double	y;
	double	z;
}				t_vector3f;

typedef struct	s_mlx {
	void	*init;
	void	*win;
	void	*img;
	char	*img_string;
	int		endian;
	int		line_size;
	int		bpp;
}				t_mlx;


typedef struct	s_brasen {
	t_vector2	delta;
	t_vector2	dir;
}				t_brasen;

typedef struct	s_transform {
	t_vector3f			rot;
	t_vector3f			mov;
	float				zoom;
	float				depth;
}				t_transform;

typedef struct	s_collection {
	char				*map_name;
	int					color;
	int					color_fade;
	int					color_id;
	t_mlx				mlx;
	t_vector3			**points;
	t_vector2			map_len;
	t_brasen			brasen;
	t_transform			transform;
}				t_collection;

int			set_zoom_and_depth(int keycode, t_collection *C);
int			set_rotation(int keycode, t_collection *C);
int			set_movement(int keycode, t_collection *C);
int			set_color(int keycode, t_collection *C);

void		rot_x(t_vector3f *v, double ang);
void		rot_y(t_vector3f *v, double ang);
void		rot_z(t_vector3f *v, double ang);

void		line(t_collection *C, t_vector2 p1, t_vector2 p2, t_rgb rgb);
t_vector3f	new_vec3f(double x, double y, double z);
int			listen_exit(void);
t_vector2	new_vec3f_projection(t_vector3f a);
void		render_this_frame(t_collection *C);
t_rgb		new_rgb(int red, int green, int blue);
t_vector2	new_vec2(int x, int y);
t_vector2	v2_scale(t_vector2 v, double scaler);
int			print_error(int error_code);
void		put_pixel_to_img(t_collection *C, t_vector2 p, t_rgb c);
int			count_len_y(t_collection *C, int fd);
int			parse_manager(t_collection *C);
t_rgb		mix_rgb(t_rgb r1, t_rgb r2);
void		display_menu(t_collection *C);
int			ft_atoi_base(const char *from, int base);
t_rgb		ui_to_rgb(unsigned int i);
#endif
