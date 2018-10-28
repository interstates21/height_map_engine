#include "fdf.h"

static char	*ft_strmultchr(const char *str, int c1, int c2)
{
	size_t i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c1 && str[i] != (char)c2)
		i++;
	if (str[i] == (char)c1 || str[i] == (char)c2)
		return ((char*)&str[i]);
	return (NULL);
}

static int		parse_line(t_collection *C,
					char *line, int n)
{
	int			i;
	char		**split;
	char		*hex_needle;

	i = 0;
	if (!(C->points[n] = (t_vector3*)malloc(sizeof(t_vector3) * C->map_len.x)))
		return (print_error(10));
	if (!(split = ft_strsplit(line, ' ')))
		return (print_error(10));
	while (i < C->map_len.x)
	{
		if (split[i])
		{
			C->points[n][i].x = i;
			C->points[n][i].y = n;
			C->points[n][i].z = CLAMP(ft_atoi(split[i]), -300, 300);
			if (C->points[n][i].z < C->min_z)
				C->min_z = C->points[n][i].z;
			if (C->points[n][i].z > C->max_z)
				C->max_z = C->points[n][i].z;
			C->points[n][i].hex_col = 0;
			if ((hex_needle = ft_strmultchr(split[i], 'x', 'X')))
				C->points[n][i].hex_col = ft_atoi_base(hex_needle + 1, 16);
			free(split[i]);
		}
		i++;
	}
	free(split);
	return (1);
}

static int		parse(t_collection *C, int fd)
{
	int		n;
	char	*line;

	n = 0;
	if (!(C->points = (t_vector3**)malloc(sizeof(t_vector3*)
		* C->map_len.y)))
		return (0);
	while (n < C->map_len.y)
	{
		get_next_line(fd, &line);
		if (!(parse_line(C, line, n)))
			return (0);
		if (line)
			free(line);
		n++;
	}
	return (1);
}

int		parse_manager(t_collection *C)
{
	int		fd;

	C->map_len.x = 0;
	C->map_len.y = 0;
	if (!(fd = open(C->map_name, O_RDONLY)))
		return (print_error(1));
	if (!count_len_y(C, fd))
		return (0);
	if (C->map_len.x < 2 || C->map_len.y < 2)
		return (print_error(5));
	close(fd);
	if (!(fd = open(C->map_name, O_RDONLY)))
		return (print_error(1));
	if (!parse(C, fd))
		return (0);
	close(fd);
	return (1);
}