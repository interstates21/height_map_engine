
#include "get_next_line.h"

static	int			append_to_string(char **file, const char *b)
{
	int		b_len;
	int		f_len;
	char	*realloc_file;

	b_len = ft_strlen(b);
	if (!(*file))
		f_len = 0;
	else
		f_len = ft_strlen(*file);
	if (!(realloc_file = ft_strnew(b_len + f_len)))
		return (0);
	if (!(*file))
		realloc_file = ft_strcpy(realloc_file, b);
	else
	{
		realloc_file = ft_strcat(ft_strcpy(realloc_file, *file), b);
		if (*file)
			free(*file);
	}
	*file = realloc_file;
	return (1);
}

static	int			parse_file(int fd, char **file)
{
	char	b[BUFF_SIZE + 1];
	int		n;

	while ((n = read(fd, b, BUFF_SIZE)) > 0)
	{
		b[n] = '\0';
		if (!append_to_string(file, b))
			return (0);
	}
	if (n == -1)
		return (0);
	return (1);
}

static	char		*new_version_of_sub(char *s, int begin, int length)
{
	char	*result;
	int		res_length;
	int		i;

	i = 0;
	result = 0;
	res_length = ft_strlen(s);
	if (s[begin] == '\n')
		begin++;
	if (s && (begin - 1 < res_length) && (length - res_length < 1))
	{
		if (!(result = ft_strnew(length)))
			return (NULL);
		while (i < length)
		{
			if (begin >= res_length)
				break ;
			result[i] = s[begin];
			++i;
			++begin;
		}
		result[i] = 0;
	}
	free(s);
	return (result);
}

int					get_next_line(const int fd, char **line)
{
	int				i;
	static	char	*file[FD_LIMIT];

	i = 0;
	if (fd < 0 || fd >= FD_LIMIT || !line)
		return (-1);
	if (BUFF_SIZE < 1)
		return (-1);
	if (!parse_file(fd, &file[fd]))
		return (-1);
	if (*file[fd] == '\0')
		return (0);
	while (file[fd][i] != '\n' && file[fd][i])
		i++;
	*line = ft_strncpy(ft_strnew(i), file[fd], i);
	file[fd] = new_version_of_sub(file[fd], i, ft_strlen(file[fd] + i));
	return (1);
}
