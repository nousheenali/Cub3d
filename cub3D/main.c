# include "minilibx/mlx.h"
# include <stdlib.h>
#include "raycaster.h"
# include <math.h>
#include <stdio.h>

int map[7][6]=
{
	{1,1,1,1,1,1},
	{1,0,0,1,0,1},
	{1,0,1,0,0,1},
	{1,1,0,0,'N',1},
	{1,1,1,1,1,1}
};

void ft_init_variables(t_game *g)
{
	g->pos.x = 4; //player pos x
	g->pos.y = 3;   //player pos y
	g->angle = 90;  //angle facing north
	g->init_dist.x = 280; //initial distance of player x direction
	g->init_dist.y = 220; //initial distance of player y direction
	g->fov = 60; //fov
	g->angle_btw_rays = g->fov/g->win_wt; //angle between subsequent rays
}

double ft_convert_deg_to_rad(double deg)
{
	return (deg * PI/180);
}

void ft_y_axis_hit(t_game *g)
{
	float alpha;
	t_vec hit;
	int x;
	int y;
	float x_inc;


	alpha = g->angle - (g->fov / 2); // angle to rightmost ray in degrees

	hit.y = (floor(g->init_dist.y/GRID) * GRID) - 1;
	hit.x = g->init_dist.x + ((g->init_dist.y - hit.y)/ tan(ft_convert_deg_to_rad(alpha)));
	printf("%f  %f\n", hit.x, hit.y);
	x = floor(hit.x/GRID);
	y = floor(hit.y/GRID);
	while (map[x][y] == 1)
	{
		y = y * GRID +GRID
	}
	printf("Wall has been hit\n");

}

//to calculate the camare plane
void start_game(t_game *g)
{
	ft_y_axis_hit(g);

	int i = 0;
	int x, y;
	int theta = g->angle - (g->fov / 2); //angle of 1st ray on the right
	t_vec hit;

	hit.y = (floor(g->init_dist.y/GRID) * GRID) - 1;
	hit.x = g->init_dist.x + ((g->init_dist.y - hit.y)/ tan(ft_convert_deg_to_rad(theta)));
	printf("%f  %f\n", hit.x, hit.y);
	int x = floor(hit.x/64);
	int y = floor(hit.y/64);
	printf("%d  %d\n", x, y);




}

int main()
{
	t_game g;
	g.win_ht = 200;
	g.win_wt = 320;
	ft_init_variables(&g);

	// g.mlx = mlx_init();
	// g.win = mlx_new_window(g.mlx, g.win_wt, g.win_ht, "cuB3d");
	start_game(&g);
	// mlx_loop(g.mlx);
}