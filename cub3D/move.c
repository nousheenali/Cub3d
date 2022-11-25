#include "raycaster.h"

//w = 13; s= 1; a= 0; d=2, esc = 53
int ft_button(int key, t_game *g)
{
	t_game *m = (t_game *) g;
	double a = 0; 
	
	a = g->angle - g->fov/2.00;
	if (key == 13) //w
	{
		mlx_clear_window(m->mlx, m->win);
		m->init_dist.x -= cos(ft_convert_deg_to_rad(a)) * 5;
		m->init_dist.y -= sin(ft_convert_deg_to_rad(a)) * 5;
		ft_start(g);
	}
	if (key == 1) //s----->moves right
	{
		mlx_clear_window(m->mlx, m->win);
		m->init_dist.x += cos(ft_convert_deg_to_rad(a)) * 5;
		m->init_dist.y += sin(ft_convert_deg_to_rad(a)) * 5;
		ft_start(g);
	}

	if (key == 53) //esc___yet to free all
	{
		mlx_destroy_window(g->mlx, g->win);
		free (g->buffer);
		exit(0);
	}
	// check_for_wall(m);
}

int ft_close(t_game *g)
{
		mlx_destroy_window(g->mlx, g->win);
		free (g->buffer);
		exit(0);
}