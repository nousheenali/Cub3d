#include "raycaster.h"

void check_for_wall(t_vec t, t_game *g)
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

double limit_ang(double a)
{
	if (a > 359.00)
		a -= 359.00;
	else if (a < 0.00)
		a += 359.00;
	return (a);
}

//w = 13; s= 1; a= 0; d=2, esc = 53
int ft_button(int key, t_game *g)
{
	t_game *m = (t_game *) g;
	int a = 0; 
	t_vec t;
	
	a = (int)(g->angle);
	t.x = g->init_dist.x;
	t.y = g->init_dist.y;
	t.a = g->angle;

	if (key == 13) //w
	{
		t.x -= (-cos(ft_convert_deg_to_rad(a)) * 5);
		t.y -= (sin(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}
	if (key == 1) //s
	{
		t.x += (-cos(ft_convert_deg_to_rad(a)) * 5);
		t.y += (sin(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}

	if (key == 0)//a
	{
		t.x -= (sin(ft_convert_deg_to_rad(a)) * 5);
		t.y += (cos(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}
	if (key == 2)
	{
		t.x += (sin(ft_convert_deg_to_rad(a)) * 5);
		t.y -= (cos(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}

	if (key == 124) //->
	{
		t.a = m->angle - 10;
		t.a = limit_ang(t.a);
		m->angle = t.a;
	}
	if (key == 123) //<-
	{
		t.a = m->angle + 10;
		t.a = limit_ang(t.a);
		m->angle = t.a;
	}

	if (key == 53) //esc___yet to free all
	{
		mlx_destroy_window(g->mlx, g->win);
		free (g->buffer);
		exit(0);
	}
	ft_start(g);
}

int ft_close(t_game *g)
{
		mlx_destroy_window(g->mlx, g->win);
		free (g->buffer);
		exit(0);
}