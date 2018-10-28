#include "fdf.h"

static	int		is_valid_symbol(char c)
{
	if (c == ' ' || c == '-' || c == '\t')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	ft_putstr("NOT VALID SYMBOL: ");
	ft_putchar(c);
	ft_putchar('\n');
	return (0);
}

static	int	skip_color_hex(char *line, int *i)
{
	int		result;

	result = 0;
	if (line[*i] == '0' && line[*i + 1] && (line[*i + 1] == 'x' || line[*i + 1] == 'X'))
	{
		*i = *i + 2;
		while (ft_isdigit(line[*i]) || (line[*i] >= 'A'
			&& line[*i] <= 'F') || (line[*i] >= 'a' && line[*i] <= 'f'))
		{
			*i = *i + 1;
			result = 1;
		}
	}
	return (result);
}

static int		count_len_x(t_collection *C, char *line, int not_first_line)
{
	int		i;
	int		temp_len;

	i = 0;
	temp_len = 0;
	while (line[i] == ' ')
		i++;
	skip_color_hex(line, &i);
	while (line[i + 1])
	{
		if (line[i] == ',')
		{
			i++;
			if (!skip_color_hex(line, &i))
				return (print_error(6));
		}
		if (!is_valid_symbol(line[i]))
			return (print_error(3));
		if (line[i] == ' ' && line[i + 1] != ' ')
			temp_len++;
		i++;
	}
	temp_len++;
	if (not_first_line && temp_len != C->map_len.x)
		return (print_error(4));
	C->map_len.x = temp_len;
	return (1);
}

int		count_len_y(t_collection *C, int fd)
{
	int i;
	char *line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!count_len_x(C, line, i))
			return (0);
		if (line)
			free(line);
		i++;
		C->map_len.y++;
	}
	return (1);

}
