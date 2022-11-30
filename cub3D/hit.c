#include "raycaster.h"

double	pythg(double x1, double x2, double y1, double y2)
{
	return (sqrt(((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1))));
}

int check_edges(t_game *g, double x, double y)
{
    if ((x > 0.00 && y > 0.00))
	{
		if (x < g->map.wt)
		{
			if (y < g->map.ht)
				return (1);
		}
	}
	return (0);
}

void ft_first_hit_y(t_game *g, float alpha, t_vec *hit)
{
    if (alpha < 180 && alpha > 0) 
    {
		hit->y = (floor(g->init_dist.y/GRID) * GRID) - 1;  // if ray facing up
        hit->x = g->init_dist.x + ((g->init_dist.y - hit->y)/ tan(ft_convert_deg_to_rad(alpha)));
    }
    if (alpha > 180 && alpha < 360) 
    {
		hit->y = (floor(g->init_dist.y/GRID) * GRID) + GRID;  // if ray facing down
        hit->x = g->init_dist.x + ((g->init_dist.y - hit->y)/ tan(ft_convert_deg_to_rad(alpha)));
    }
    if (alpha == 180 || alpha == 0 || alpha == 360) 
    {
        hit->y = g->init_dist.y;
        hit->x = g->init_dist.x; 
    }
}

double ft_y_axis_hit(t_game *g, float alpha)
{
	t_vec hit;
	int x;
	int y;

    ft_first_hit_y(g, alpha, &hit);
    x = floor(hit.x/GRID);
	y = floor(hit.y/GRID);
    if(!check_edges(g, hit.x, hit.y))
        return (pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
	while (g->map.map[y][x] != '1' && g->map.map[y][x])
	{
		if ((alpha >= 180 && alpha <= 360) || alpha == 0)
        {
			hit.y = hit.y + GRID ;
            hit.x = hit.x - GRID/ tan(ft_convert_deg_to_rad(alpha));
        }
		if (alpha < 180 && alpha > 0) 
        {
			hit.y = hit.y - GRID ;
            hit.x = hit.x + GRID / tan(ft_convert_deg_to_rad(alpha));
        }
		x = floor(hit.x/GRID);
		y = floor(hit.y/GRID);
        if(!check_edges(g, hit.x, hit.y))
            return (pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
	}
	return (pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
}

void ft_first_hit_x(t_game *g, float alpha, t_vec *hit)
{
    float i;
    if (alpha > 90 && alpha < 270) 
    {
        hit->x = (floor(g->init_dist.x/GRID) * GRID) - 1;  // if ray facing left
        hit->y = g->init_dist.y + ((g->init_dist.x - hit->x) * tan(ft_convert_deg_to_rad(alpha)));
    }
    if (alpha < 90 || alpha > 270) 
    {
		hit->x = (floor(g->init_dist.x/GRID) * GRID) + GRID;  // if ray facing left
        hit->y = g->init_dist.y + ((g->init_dist.x - hit->x) * tan(ft_convert_deg_to_rad(alpha)));
    }
    if (alpha == 90 || alpha == 270) 
    {
        hit->y = g->init_dist.y;
        hit->x = g->init_dist.x; 
    }
}

double ft_x_axis_hit(t_game *g, float alpha)
{
	t_vec hit;
	int x;
	int y;

    ft_first_hit_x(g, alpha, &hit);
    x = floor(hit.x/GRID);
	y = floor(hit.y/GRID);
    if(!check_edges(g, hit.x, hit.y))
        return (pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
	while (g->map.map[y][x] != '1')
	{
		if (alpha >= 90 && alpha <= 270)
        {
			hit.x = hit.x - GRID ;
            hit.y = hit.y + GRID*tan(ft_convert_deg_to_rad(alpha));;
        }
		if (alpha < 90 || alpha > 270) 
        {
			hit.x =hit.x + GRID ;
            hit.y = hit.y - GRID*tan(ft_convert_deg_to_rad(alpha));;
        }
		x = floor(hit.x/GRID);
		y = floor(hit.y/GRID);
        if(!check_edges(g, hit.x, hit.y))
            return (pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
    
	}
	return (pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
}