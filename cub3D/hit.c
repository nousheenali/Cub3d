/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:17:27 by nali              #+#    #+#             */
/*   Updated: 2022/11/22 16:09:33 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

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
	// printf("%f  %f\n", hit.x, hit.y);
	// printf("%d  %d\n", x, y);
	while (map[y][x] != 1)
	{
		if (alpha >= 180 && alpha <= 360)
        {
			hit.y = hit.y + GRID ;
            hit.x = hit.x + GRID/tan(ft_convert_deg_to_rad(alpha));
        }
		if (alpha < 180 && alpha > 0) 
        {
			hit.y = hit.y - GRID ;
            hit.x = hit.x + GRID/tan(ft_convert_deg_to_rad(alpha));
        }
        if (alpha == 0) 
            hit.x = hit.x + GRID;
        if (alpha == 180) 
            hit.x = hit.x - GRID;
		x = floor(hit.x/GRID);
		y = floor(hit.y/GRID);
		// printf("%f  %f\n", hit.x, hit.y);
		// printf("%d  %d\n", x, y);
	}
	printf("Wall has been hit on y-axis\n");
	return (hit.y);
}

void ft_first_hit_x(t_game *g, float alpha, t_vec *hit)
{
    float i;
    if (alpha > 90 && alpha < 270) 
    {
        hit->x = (floor(g->init_dist.x/GRID) * GRID) - 1;  // if ray facing left
        i =  tan(ft_convert_deg_to_rad(alpha));
        printf(" tan val = %f\n", i);
        printf(" %f - %f = %f\n", g->init_dist.x, hit->x, (g->init_dist.x - hit->x));
        hit->y = g->init_dist.y + ((g->init_dist.x - hit->x) * i);
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
	printf("%f  %f\n", hit.x, hit.y);
	printf("%d  %d\n", x, y);
	while (map[y][x] != 1)
	{
		if (alpha > 90 && alpha < 270)
        {
			hit.x = hit.x - GRID ;
            hit.y = hit.y - GRID/tan(ft_convert_deg_to_rad(alpha));;
        }
		if (alpha < 90 || alpha > 270) 
        {
			hit.x =hit.x + GRID ;
            hit.y = hit.y - GRID/tan(ft_convert_deg_to_rad(alpha));;
        }
        if (alpha == 90)
            hit.y = hit.y - GRID;
        if (alpha == 270) 
            hit.y = hit.y + GRID;
		x = floor(hit.x/GRID);
		y = floor(hit.y/GRID);
		// printf("%f  %f\n", hit.x, hit.y);
		// printf("%d  %d\n", x, y);
	}
    printf("%f  %f\n", hit.x, hit.y);
	printf("%d  %d\n", x, y);
	printf("Wall has been hit on x-axis\n");
	return (hit.x);
}
