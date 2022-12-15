/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:07:27 by nali              #+#    #+#             */
/*   Updated: 2022/12/03 12:56:21 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_get_proj_top_bottom(t_game *g, int *top, int *bottom)
{
	*top = (int)(g->win_ht / 2) - (int)(g->proj_h / 2);
	if (*top < 0)
		*top = 0;
	*bottom = (int)(g->win_ht / 2) + (int)(g->proj_h / 2);
	if (*bottom >= g->win_ht)
		*bottom = g->win_ht - 1;
}

void	ft_get_ray_direction(double alpha, t_vec *rayDir)
{
	rayDir->x = cos(ft_convert_deg_to_rad(alpha));
	rayDir->y = sin(ft_convert_deg_to_rad(alpha));
}

void	get_side(t_game *g, t_vec rayDir)
{
	if (g->side == 0)
	{
		if (rayDir.x < 0)
			g->side = 1;
		else
			g->side = 2;
	}
	else
	{
		if (rayDir.y < 0)
			g->side = 3;
		else
			g->side = 4;
	}
}
