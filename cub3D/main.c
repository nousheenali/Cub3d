

#include "raycaster.h"

// int map[13][8]=
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1}
// };

int map[5][6]=
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
	int	k;

	i = -1;
	g->buffer = (unsigned int **)malloc(g->win_ht * sizeof(unsigned int *));
	while (++i < g->win_ht)
		g->buffer[i] = (unsigned int *)malloc(g->win_wt * sizeof(unsigned int));
	i = -1;
	while (++i < g->win_ht)
	{
		k = -1;
		while (++k < g->win_wt)
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

	// g->pos.x = 3; //player pos x
	// g->pos.y = 4;   //player pos y
	g->angle = 180;  //angle facing north
	g->init_dist.x = 200; //initial distance of player x direction
	g->init_dist.y = 220; //initial distance of player y direction
	g->fov = 60; //fov
	g->map_height = 320; //map height * GRID
	g->map_width = 384; //map width * GRID
	g->angle_btw_rays = g->fov/g->win_wt; //angle between subsequent rays
	rad = ft_convert_deg_to_rad(g->fov / 2) ;
	g->dist_proj = (g->win_wt / 2) / tan(rad);
	ft_create_buffer_init(g);
}

double ft_get_projected_height(t_game *g, double alpha, t_vec hit, double beta)
{
	double y_dist;
	double x_dist;
	double ray_length;
	double proj_h;

	x_dist = hit.x;
	y_dist = hit.y;
	
	// y_dist = fabs((hit.y - g->init_dist.y )/ sin(ft_convert_deg_to_rad(alpha)));
	// x_dist = fabs((g->init_dist.x - hit.x) / cos(ft_convert_deg_to_rad(alpha)));
	if (x_dist < y_dist)
		ray_length = x_dist * cos(ft_convert_deg_to_rad(beta));//correcting fish eye
	else
		ray_length = y_dist * cos(ft_convert_deg_to_rad(beta)); //correcting fish eye
	// //ray_length is the actual length of the ray when it hits the wall
	proj_h = (GRID * g->dist_proj) / ray_length;
	return (proj_h);
}

void ft_populate_buffer(t_game *g, double proj_h, int x)
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
		g->buffer[y][x] = 0x8545e6;
}

//to calculate the camare plane
void start_game(t_game *g)
{
	int i;
	double alpha;
	double beta;
	t_vec hit;
	double proj_h;//projected height
	double x,y;

	i = -1;
	alpha = g->angle + (g->fov / 2); // angle to rightmost ray in degrees
	beta = g->fov/2;
	while(++i < g->win_wt)
	{

    	printf("=============================\n");
		printf("alpha = %f\n",alpha);
		printf("beta = %f\n",beta);
		hit.y = ft_y_axis_hit(g, alpha);
		hit.x = ft_x_axis_hit(g, alpha);
		printf("hit.x = %f hit.y = %f \n",hit.x, hit.y);
		proj_h = ft_get_projected_height(g, alpha, hit, beta);
		ft_populate_buffer(g, proj_h, i);
		printf("projected height= %f \n",proj_h);
		alpha = alpha - g->angle_btw_rays;
		if(alpha <= g->angle)
			beta = beta + g->angle_btw_rays;
		else
			beta = beta - g->angle_btw_rays;
	}
}

int main()
{
	t_game g;
	int i;
	int k;
	g.win_ht = 400;
	g.win_wt = 640;
	
	ft_init_variables(&g);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.win_wt, g.win_ht, "cuB3d");
	g.img = mlx_new_image(g.mlx, g.win_wt, g.win_ht);
	g.data = (int *)mlx_get_data_addr(g.img, &g.bits, &g.lines, &g.endian);
	start_game(&g);
	i = -1;
	while (++i < g.win_ht)
	{
		k = -1;
		while (++k < g.win_wt)
			g.data[i * g.win_wt + k] = g.buffer[i][k];
	}
	mlx_put_image_to_window(g.mlx, g.win, g.img, 0, 0);
	mlx_loop(g.mlx);
}