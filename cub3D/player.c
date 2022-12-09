/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:52:57 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 16:00:17 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	set_ang(t_game *g, int i, int j)
{
	if (g->map.map[i][j] == 'N')
		g->angle = 90;
	else if (g->map.map[i][j] == 'W')
		g->angle = 180;
	else if (g->map.map[i][j] == 'S')
		g->angle = 270;
	else if (g->map.map[i][j] == 'E')
		g->angle = 360;
	g->map.map[i][j] = '0';
}

void	ft_find_ply_posi(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (++j < (int)(g->map.wt / 64))
		{
			if (g->map.map[i][j] == 'N' || g->map.map[i][j] == 'S'
				|| g->map.map[i][j] == 'E' || g->map.map[i][j] == 'W')
			{
				g->init_dist.y = (i * 64.0) + 32;
				g->init_dist.x = (j * 64.0) + 32;
				if (g->map.map[i][j] == 'N' || g->map.map[i][j] == 'S'
				|| g->map.map[i][j] == 'E' || g->map.map[i][j] == 'W')
					set_ang(g, i, j);
			}
		}
	}
}
