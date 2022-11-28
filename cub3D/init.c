#include "raycaster.h"

void	ft_create_buffer(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	g->buffer = (unsigned int **)malloc(g->win_ht * sizeof(unsigned int *));
	while (++i < g->win_ht)
		g->buffer[i] = (unsigned int *)malloc(g->win_wt * sizeof(unsigned int));
	i = -1;
	while (++i < g->win_ht)
	{
		j = -1;
		while (++j < g->win_wt)
			g->buffer[i][j] = 0;
	}
}

void ft_init_variables(t_game *g)
{
	double rad;

	//screen
	g->win_wt = 640; 
	g->win_ht = 400;

	//mlx initialization
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->win_wt, g->win_ht, "cuB3d");
	g->img = mlx_new_image(g->mlx, g->win_wt, g->win_ht);
	g->data = (int *)mlx_get_data_addr(g->img, &g->bits, &g->lines, &g->endian);

	//player pos and direction
	g->pos.ax.x = 608; 	
	g->pos.ax.y = 280;


	g->pos.vc.a = 280;  //Need vc for movement... but what is the initial value
	g->pos.vc.x = cos(ft_convert_deg_to_rad(280.00));
	g->pos.vc.y = sin(ft_convert_deg_to_rad(280.00));
	g->init_dist.x = 608; //initial distance of player x direction
	g->init_dist.y = 280;

	//for screen color
	ft_create_buffer(g);

	//for rays
	g->angle = 135;
	g->fov = 60;
	g->n_rays = g->win_wt;
	g->angle_btw_rays = g->fov / g->win_wt;

	//idk why we need this
	rad = ft_convert_deg_to_rad(g->fov / 2) ;
	g->dist_proj = (g->win_wt / 2) / tan(rad); //projection plane distance
}