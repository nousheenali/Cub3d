/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:03:46 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/14 09:51:51 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	move_front_back(t_game *g, t_vec t, int key)
{
	if (key == 13)
	{
		t.x -= (-cos(ft_convert_deg_to_rad(g->angle)) * 5);
		t.y -= (sin(ft_convert_deg_to_rad(g->angle)) * 5);
		check_for_wall(t, g);
	}
	if (key == 1)
	{
		t.x += (-cos(ft_convert_deg_to_rad(g->angle)) * 5);
		t.y += (sin(ft_convert_deg_to_rad(g->angle)) * 5);
		check_for_wall(t, g);
	}
}

void	move_right_left(t_game *g, t_vec t, int key)
{
	if (key == 0)
	{
		t.x -= (sin(ft_convert_deg_to_rad(g->angle)) * 5);
		t.y -= (cos(ft_convert_deg_to_rad(g->angle)) * 5);
		check_for_wall(t, g);
	}
	if (key == 2)
	{
		t.x += (sin(ft_convert_deg_to_rad(g->angle)) * 5);
		t.y += (cos(ft_convert_deg_to_rad(g->angle)) * 5);
		check_for_wall(t, g);
	}
}

void	ft_rotate(t_game *g, t_vec t, int key)
{
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
}

int	ft_button(int key, t_game *g)
{
	t_vec	t;

	t.x = g->init_dist.x;
	t.y = g->init_dist.y;
	t.a = g->angle;
	if (key == 13 || key == 1)
		move_front_back(g, t, key);
	else if (key == 0 || key == 2)
		move_right_left(g, t, key);
	else if (key == 124 || key == 123)
		ft_rotate(g, t, key);
	if (key == 53)
		ft_close(g);
	ft_start(g);
	return (0);
}

int	ft_close(t_game *g)
{
	int	i;

	i = -1;
	mlx_destroy_window(g->mlx, g->win);
	if (g->buffer)
	{
		while (++i < g->win_ht)
			free (g->buffer[i]);
		free(g->buffer);
	}
	ft_error_before(g, "");
	exit(0);
}
