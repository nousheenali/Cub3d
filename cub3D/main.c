#include "raycaster.h"

double ft_convert_deg_to_rad(double deg)
{
	return (deg * PI/180.0);
}


int main(int argc, char **argv)
{
	t_game g;

	if (argc != 2)
	{
		printf("Wrong no. of arg!! Try ./cub3D map");
		return (1);
	}
	parse_map(&g, argv[1]);
	ft_init_variables(&g);
	ft_start(&g);
	mlx_hook(g.win, 2, 0, &ft_button, &g);
	mlx_hook(g.win, 17, 0, ft_close, &g); //handles x-mouse click
	mlx_loop(g.mlx);
}
