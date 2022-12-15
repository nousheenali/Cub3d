/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:04:07 by nali              #+#    #+#             */
/*   Updated: 2022/12/06 15:32:41 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

double	ft_get_projected_height(t_game *g, t_vec dist, double beta)
{
	double	ray_length;
	double	proj_h;

	if (dist.x < dist.y)
	{
		g->side = 0;
		ray_length = dist.x * cos(ft_convert_deg_to_rad(beta));
	}
	else
	{
		g->side = 1;
		ray_length = dist.y * cos(ft_convert_deg_to_rad(beta));
	}
	proj_h = (GRID * g->dist_proj) / ray_length;
	return (proj_h);
}

void	ft_limit_alpha_beta(t_game *g, double *alpha, double *beta, int *flag)
{
	if (*alpha > 0)
		*alpha = *alpha - g->angle_btw_rays;
	if (*alpha <= 0)
		*alpha += 359;
	if (*flag == 1)
		*beta = *beta + g->angle_btw_rays;
	else
		*beta = *beta - g->angle_btw_rays;
	if (*beta == 0.00)
		*flag = 1;
}

void	start_game(t_game *g)
{
	int		i;
	double	alpha;
	double	beta;
	t_vec	dist;
	int		flag;

	i = -1;
	flag = 0;
	alpha = g->angle + (g->fov / 2.0);
	beta = g->fov / 2;
	if (alpha > 359)
		alpha = alpha - 360;
	else if (alpha < 0)
		alpha = alpha + 360;
	while (++i < g->win_wt)
	{
		dist.y = ft_y_axis_hit(g, alpha);
		dist.x = ft_x_axis_hit(g, alpha);
		g->proj_h = ft_get_projected_height(g, dist, beta);
		ft_populate_buffer(g, g->proj_h, i);
		ft_texture(g, alpha, dist, i);
		ft_limit_alpha_beta(g, &alpha, &beta, &flag);
	}
}

void	ft_start(t_game *g)
{
	int	i;
	int	k;

	i = -1;
	ft_clear_buffer(g->buffer, g);
	start_game(g);
	while (++i < g->win_ht)
	{
		k = -1;
		while (++k < g->win_wt)
		{
			g->data[i * g->win_wt + k] = g->buffer[i][k];
			if (ft_ceiling(g->buffer, i, k))
				g->data[i * g->win_wt + k] = g->map.ce;
			else if (ft_floor(g->buffer, i, k, g))
				g->data[i * g->win_wt + k] = g->map.fl;
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}
