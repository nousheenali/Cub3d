/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:03:46 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/07 11:56:41 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	check_for_wall(t_vec t, t_game *g)
{
	int	x;
	int	y;

	x = (int)(t.x / GRID);
	y = (int)(t.y / GRID);
	if (g->map.map[y][x] != '1')
	{
		g->init_dist.x = t.x;
		g->init_dist.y = t.y;
	}
}

double	limit_ang(double a)
{
	if (a > 359.00)
		a -= 359.00;
	else if (a < 0.00)
		a += 359.00;
	return (a);
}

int ft_button(int key, t_game *g)
{
	t_vec	t;
	int		a;

	a = (int)(g->angle);
	t.x = g->init_dist.x;
	t.y = g->init_dist.y;
	t.a = g->angle;
	if (key == 13)
	{
		t.x -= (-cos(ft_convert_deg_to_rad(a)) * 5);
		t.y -= (sin(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}
	if (key == 1)
	{
		t.x += (-cos(ft_convert_deg_to_rad(a)) * 5);
		t.y += (sin(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}
	if (key == 0)
	{
		t.x -= (sin(ft_convert_deg_to_rad(a)) * 5);
		t.y -= (cos(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}
	if (key == 2)
	{
		t.x += (sin(ft_convert_deg_to_rad(a)) * 5);
		t.y += (cos(ft_convert_deg_to_rad(a)) * 5);
		check_for_wall(t, g);
	}
	if (key == 124)
	{
		t.a = g->angle - 10;
		t.a = limit_ang(t.a);
		g->angle = t.a;
	}
	if (key == 123)
	{
		t.a = g->angle + 10;
		t.a = limit_ang(t.a);
		g->angle = t.a;
	}
	if (key == 53)
	{
		mlx_destroy_window(g->mlx, g->win);
		free (g->buffer);
		exit(0);
	}
	ft_start(g);
}

int	ft_close(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	free (g->buffer);
	exit(0);
}
