/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:49:18 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/14 10:41:14 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_create_buffer(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	g->buffer = malloc((g->win_ht + 1) * sizeof(unsigned int *));
	while (++i < g->win_ht)
		g->buffer[i] = malloc((g->win_wt) * sizeof(unsigned int));
	i = -1;
	while (++i < g->win_ht)
	{
		j = -1;
		while (++j < g->win_wt)
			g->buffer[i][j] = 0;
	}
}

void	ft_valid_ply(t_game *g)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (++j < (int)(g->map.wt / 64))
		{
			if (g->map.map[i][j] == 'N' || g->map.map[i][j] == 'S'
				|| g->map.map[i][j] == 'E' || g->map.map[i][j] == 'W')
				flag++;
		}
	}
	if (flag != 1)
	{
		ft_error_before(g, "Error : with player position!!!\n");
		exit (1);
	}
}

void	ft_init_variables(t_game *g)
{
	double	rad;

	g->win_wt = 640;
	g->win_ht = 400;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->win_wt, g->win_ht, "cuB3d");
	g->img = mlx_new_image(g->mlx, g->win_wt, g->win_ht);
	g->data = (int *)mlx_get_data_addr(g->img, &g->bits, &g->lines, &g->endian);
	ft_create_buffer(g);
	g->fov = 60;
	g->n_rays = g->win_wt;
	g->angle_btw_rays = g->fov / g->win_wt;
	rad = ft_convert_deg_to_rad(g->fov / 2);
	g->dist_proj = (g->win_wt / 2) / tan(rad);
}

void	ft_init(t_map *m)
{
	m->map = NULL;
	m->wt = 0.0;
	m->ht = 0.0;
}
