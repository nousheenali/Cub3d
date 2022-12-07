#include "raycaster.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		printf("Wrong no. of arg!! Try ./cub3D map");
		return (1);
	}
	parse_map(&g, argv[1]);
	ft_init_variables(&g);
	if (ft_convert_xpm_to_img(&g))
		return (1);
	ft_start(&g);
	mlx_hook(g.win, 2, 0, &ft_button, &g);
	mlx_hook(g.win, 17, 0, ft_close, &g); //handles x-mouse click
	mlx_loop(g.mlx);
}
