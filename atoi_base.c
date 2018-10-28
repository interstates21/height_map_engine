#include "fdf.h"

static int	ascii_fix(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (0);
}

static int	check_base(int c, int base)
{
	if (ft_isdigit(c) && (c - '0') < base)
		return (1);
	if (c >= 'A' && c <= 'Z' && (c - 'A' + 10) < base)
		return (1);
	if (c >= 'a' && c <= 'z' && (c - 'a' + 10) < base)
		return (1);
	return (0);
}

int	ft_atoi_base(const char *from, int base)
{
	int	ret;
	int	sign;
	int i;

	if (!from)
		return (0);
	if (base < 2 || base > 16)
		return (0);
	ret = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(from[i]))
		i++;
	if (from[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (from[i] == '+')
		i++;
	while (check_base(from[i], base))
	{
		ret = ret * base + ascii_fix(from[i]);
		i++;
	}
	return (ret * sign);
}