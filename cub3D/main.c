# include "minilibx/mlx.h"
# include <stdlib.h>
#include "raycaster.h"
# include <math.h>
#include <stdio.h>

int map[7][6]=
{
	{1,1,1,1,1,1},
	{1,0,0,0,0,1},
	{1,0,0,0,0,1},
	{1,0,0,0,'N',1},
	{1,1,1,1,1,1}
};

void	ft_create_buffer_init(t_game *g)
{
	int	i;
	// int	k;

	i = -1;
	g->buffer = (unsigned int**) malloc(sizeof(unsigned  int) * g->win_ht);
	while (++i < g->win_wt)
		g->buffer[i] = (unsigned int*) malloc(sizeof(unsigned  int) * g->win_wt);
	i = -1
	while (++i < g->win_wt)
	{
		k = -1;
		while (++k < g->win_ht)
			g->buffer[i][k] = 0;
	}
}

double ft_convert_deg_to_rad(double deg)
{
	return (deg * PI/180);
}

void ft_init_variables(t_game *g)
{
	double rad;


	g->pos.x = 3; //player pos x
	g->pos.y = 4;   //player pos y
	g->angle = 90;  //angle facing north
	g->init_dist.x = 280; //initial distance of player x direction
	g->init_dist.y = 220; //initial distance of player y direction
	g->fov = 60; //fov
	g->angle_btw_rays = g->fov/g->win_wt; //angle between subsequent rays
	rad = ft_convert_deg_to_rad(g->fov / 2) ;
	g->dist_proj = (g->win_wt / 2) / tan(rad);
	ft_create_buffer_init(g);
}


double ft_y_axis_hit(t_game *g, float alpha)
{
	t_vec hit;
	int x;
	int y;
	float x_inc;

	x_inc =  GRID/tan(ft_convert_deg_to_rad(alpha));
	if (alpha >= 180 && alpha <= 360) 
		hit.y = (floor(g->init_dist.y/GRID) * GRID) + GRID;  // if ray facing down
	else  
		hit.y = (floor(g->init_dist.y/GRID) * GRID) - 1;  // if ray facing up
	hit.x = g->init_dist.x + ((g->init_dist.y - hit.y)/ tan(ft_convert_deg_to_rad(alpha)));
	x = floor(hit.x/GRID);
	y = floor(hit.y/GRID);
	// printf("%f  %f\n", hit.x, hit.y);
	// printf("%d  %d\n", x, y);
	while (map[y][x] != 1)
	{
		if (alpha >= 180 && alpha <= 360)
			hit.y = hit.y + GRID ;
		else
			hit.y = hit.y - GRID ;
		hit.x = hit.x+ x_inc;
		x = floor(hit.x/GRID);
		y = floor(hit.y/GRID);
		// printf("%f  %f\n", hit.x, hit.y);
		// printf("%d  %d\n", x, y);
	}
	printf("Wall has been hit on y-axis\n");
	return (hit.y);
}

double ft_x_axis_hit(t_game *g, float alpha)
{
	t_vec hit;
	int x;
	int y;
	float y_inc;

	y_inc =  GRID/tan(ft_convert_deg_to_rad(alpha));
	if (alpha >= 90 && alpha <= 270)
		hit.x = (floor(g->init_dist.x/GRID) * GRID) - 1;  // if ray facing left
	else
		hit.x = (floor(g->init_dist.x/GRID) * GRID) + GRID;  // if ray facing right
	hit.y = g->init_dist.y + ((g->init_dist.x - hit.x)/ tan(ft_convert_deg_to_rad(alpha)));
	x = floor(hit.x/GRID);
	y = floor(hit.y/GRID);
	// printf("%f  %f\n", hit.x, hit.y);
	// printf("%d  %d\n", x, y);
	while (map[y][x] != 1)
	{
		if (alpha >= 90 && alpha <= 270)
			hit.x =hit.x - GRID ;
		else
			hit.x =hit.x + GRID ;
		hit.y = hit.y - y_inc;
		x = floor(hit.x/GRID);
		y = floor(hit.y/GRID);
		// printf("%f  %f\n", hit.x, hit.y);
		// printf("%d  %d\n", x, y);
	}
	printf("Wall has been hit on x-axis\n");
	return (hit.x);
}

//to calculate the camare plane
void start_game(t_game *g)
{
	int i = 0;
	double alpha;
	double beta;
	t_vec hit;
	double y_dist;
	double x_dist;
	double ray_length;
	double proj_h;//projected height


	alpha = g->angle + (g->fov / 2); // angle to rightmost ray in degrees
	beta = g->fov/2;
	// while(i < g->win_wt)
	// {
		printf("alpha = %f\n",alpha);
		hit.y = ft_y_axis_hit(g, alpha);
		hit.x = ft_x_axis_hit(g, alpha);
		// printf("%f %f\n", hit.x, hit.y);
		y_dist = fabs((hit.y - g->init_dist.y )/ sin(ft_convert_deg_to_rad(alpha)));
		x_dist = fabs((g->init_dist.x - hit.x) / cos(ft_convert_deg_to_rad(alpha)));
		// printf("%f %f\n", x_dist, y_dist);
		if (x_dist < y_dist)
			ray_length = x_dist * cos(ft_convert_deg_to_rad(beta));//correcting fish eye
		else
			ray_length = y_dist * cos(ft_convert_deg_to_rad(beta)); //correcting fish eye
		proj_h = (GRID * g->dist_proj) / ray_length;
		alpha = alpha + g->angle_btw_rays;
		beta = beta + g->angle_btw_rays;
		i++;
	// }
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