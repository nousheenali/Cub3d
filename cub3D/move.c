#include "raycaster.h"

void check_for_wall(t_axis t, t_game *g)
{
	int x = t.x/GRID;
	int y = t.y/GRID;

	printf("x y = %d %d\n", x, y);
	if (g->map.map[y][x] != '1')
	{
		g->init_dist.x = t.x;
		g->init_dist.y = t.y;
	}
}

//w = 13; s= 1; a= 0; d=2, esc = 53
int ft_button(int key, t_game *g)
{
	t_game *m = (t_game *) g;
	int a = 0; 
	t_axis t;
	
	a = (int)(g->angle);
	t.x = g->init_dist.x;
	t.y = g->init_dist.y;

	// printf("%d\n", key);
	if (key == 13) //w
	{
		// mlx_clear_window(m->mlx, m->win);
		printf("initial dis: %f %f\n", m->init_dist.x, m->init_dist.y);
		printf("temp dist: %f %f\n", t.x, t.y);
		printf("angle dist: %f %f\n", cos(ft_convert_deg_to_rad(a)), sin(ft_convert_deg_to_rad(a)));

		t.x -= (-cos(ft_convert_deg_to_rad(a)) * 5);
		t.y -= (sin(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
		// ft_start(g);
	}
	if (key == 1) //s----->moves right
	{
		// mlx_clear_window(m->mlx, m->win);
		// mlx_clear_window(m->mlx, m->win);
		printf("initial dis: %f %f\n", m->init_dist.x, m->init_dist.y);
		printf("temp dist: %f %f\n", t.x, t.y);
		printf("angle dist: %f %f\n", cos(ft_convert_deg_to_rad(a)), sin(ft_convert_deg_to_rad(a)));

		t.x += (cos(ft_convert_deg_to_rad(a)) * 5);
		t.y += (sin(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}

	if (key == 53) //esc___yet to free all
	{
		mlx_destroy_window(g->mlx, g->win);
		free (g->buffer);
		exit(0);
	}
	// check_for_wall(m);
	if (key == 124) //->
	{
		mlx_clear_window(m->mlx, m->win);
		m->angle += 8;
		// ft_start(g);
	}
	if (key == 123) //<-
	{
		mlx_clear_window(m->mlx, m->win);
		m->angle -= 8;
		// ft_start(g);
	}
	ft_start(g);
}

int ft_close(t_game *g)
{
		mlx_destroy_window(g->mlx, g->win);
		free (g->buffer);
		exit(0);
}