#include "fdf.h"

int		listen_exit(void)
{
	exit(0);

	return (0);
}

int		print_error(int error_code)
{
	if (error_code == 0)
		ft_putendl("USAGE: ./fdf [MAPNAME]");
	if (error_code == 1)
		ft_putendl("FILE IS NOT VALID");
	if (error_code == 2)
		ft_putendl("MLX ERROR");
	if (error_code == 3)
		ft_putendl("VALID MAP SYMBOLS: [(0 - 9), (,), ( ), (-), (0x...)]");
	if (error_code == 4)
		ft_putendl("ALL MAPLINES MUST CONTAIN THE SAME AMOUNT OF ELEMENTS");
	if (error_code == 5)
		ft_putendl("THE MAP IS TOO SMALL");
	if (error_code == 6)
		ft_putendl("CAN'T READ A HEX COLOR");
	if (error_code == 10)
		ft_putendl("SYSTEM ERROR");
	return (0);
}