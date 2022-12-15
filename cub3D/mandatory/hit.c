/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:24 by nali              #+#    #+#             */
/*   Updated: 2022/12/06 15:12:44 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	check_edges(t_game *g, double x, double y)
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

void	ft_first_hit_y(t_game *g, float alpha, t_vec *hit)
{
	double	tan_val;

	tan_val = tan(ft_convert_deg_to_rad(alpha));
	if (alpha < 180 && alpha > 0)
	{
		hit->y = (floor(g->init_dist.y / GRID) * GRID) - 1;
		hit->x = g->init_dist.x + ((g->init_dist.y - hit->y) / tan_val);
	}
	if (alpha > 180 && alpha < 360)
	{
		hit->y = (floor(g->init_dist.y / GRID) * GRID) + GRID;
		hit->x = g->init_dist.x + ((g->init_dist.y - hit->y) / tan_val);
	}
	if (alpha == 180 || alpha == 0 || alpha == 360)
	{
		hit->y = g->init_dist.y;
		hit->x = g->init_dist.x;
	}
}

double	ft_y_axis_hit(t_game *g, float alpha)
{
	t_vec	hit;
	int		x;
	int		y;

	ft_first_hit_y(g, alpha, &hit);
	ft_get_floor_values(hit, &x, &y);
	if (!check_edges(g, hit.x, hit.y))
		return (ft_pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
	while (g->map.map[y][x] == '0' && g->map.map[y][x])
	{
		if ((alpha >= 180 && alpha <= 360) || alpha == 0)
		{
			hit.y = hit.y + GRID ;
			hit.x = hit.x - GRID / tan(ft_convert_deg_to_rad(alpha));
		}
		if (alpha < 180 && alpha > 0)
		{
			hit.y = hit.y - GRID ;
			hit.x = hit.x + GRID / tan(ft_convert_deg_to_rad(alpha));
		}
		ft_get_floor_values(hit, &x, &y);
		if (!check_edges(g, hit.x, hit.y))
			return (ft_pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
	}
	return (ft_pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
}

void	ft_first_hit_x(t_game *g, float alpha, t_vec *hit)
{
	double	tan_val;

	tan_val = tan(ft_convert_deg_to_rad(alpha));
	if (alpha > 90 && alpha < 270)
	{
		hit->x = (floor(g->init_dist.x / GRID) * GRID) - 1;
		hit->y = g->init_dist.y + ((g->init_dist.x - hit->x) * tan_val);
	}
	if (alpha < 90 || alpha > 270)
	{
		hit->x = (floor(g->init_dist.x / GRID) * GRID) + GRID;
		hit->y = g->init_dist.y + ((g->init_dist.x - hit->x) * tan_val);
	}
	if (alpha == 90 || alpha == 270)
	{
		hit->y = g->init_dist.y;
		hit->x = g->init_dist.x;
	}
}

double	ft_x_axis_hit(t_game *g, float alpha)
{
	t_vec	hit;
	int		x;
	int		y;

	ft_first_hit_x(g, alpha, &hit);
	ft_get_floor_values(hit, &x, &y);
	if (!check_edges(g, hit.x, hit.y))
		return (ft_pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
	while (g->map.map[y][x] == '0')
	{
		if (alpha >= 90 && alpha <= 270)
		{
			hit.x = hit.x - GRID ;
			hit.y = hit.y + GRID * tan(ft_convert_deg_to_rad(alpha));
		}
		if (alpha < 90 || alpha > 270)
		{
			hit.x = hit.x + GRID;
			hit.y = hit.y - GRID * tan(ft_convert_deg_to_rad(alpha));
		}
		ft_get_floor_values(hit, &x, &y);
		if (!check_edges(g, hit.x, hit.y))
			return (ft_pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
	}
	return (ft_pythg(g->init_dist.x, hit.x, g->init_dist.y, hit.y));
}
