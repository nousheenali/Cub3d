#include "raycaster.h"

double ft_convert_deg_to_rad(double deg)
{
	return (deg * PI/180.0);
}

//IS THIS NEEDED???
//*********************************************
void ft_populate_buffer_2(t_game *g, double proj_h, int x)
{
	int top;
	int bottom;
	int y;
	
	top = (g->win_ht / 2) - (int)(proj_h / 2);
	if (top < 0)
		top = 0;
	bottom = (g->win_ht / 2) + (int)(proj_h / 2);
	if (bottom >= g->win_ht)
		bottom = g->win_ht - 1;
	y = (top - 1);
	while (++y < bottom)
		g->buffer[y][x] = 0xff0000;
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
