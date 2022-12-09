/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:22:45 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 16:21:57 by sfathima         ###   ########.fr       */
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

void	set_value(int *i, int *k, int *l, int flag)
{
	if (flag == 1)
		*i = -1;
	else
		*i = 0;
	*k = 1;
	*l = 0;
}

void	set_value1(int *i, int *k, int *l, t_game *g)
{
	*i = (int)g->map.ht / 64;
	*k = 1;
	*l = 0;
}

void	check_end(t_game *g, int i, int j)
{
	if (i == 0 || i == (int)(g->map.ht / 64) - 1)
	{
		if (g->map.map[i][j] != '1' && g->map.map[i][j] != ' '
			&& g->map.map[i][j] != 'x')
		{
			ft_error_before(g, "-map error");
			exit(1);
		}
	}
}

void	ft_check1(t_game *g, int i, int j, int *n)
{
	if (j == ft_strlen(g->map.map[i]))
	{
		if (g->map.map[i + n[0]][j - 1] != '1' \
		|| g->map.map[i + n[0]][j] != '1')
		{
			ft_error_before(g, "*map error");
			exit (1);
		}
	}
	if (g->map.map[i + n[0]][j - 1] == '1' && g->map.map[i + n[0]][j + 1] \
	== '1' && g->map.map[i + n[0]][j] != '1')
		n[0]++;
	else if (g->map.map[i + n[0]][j - 1] == '1' && g->map.map[i + n[0]][j] \
	== '1' && g->map.map[i + n[0]][j + 1] == '1')
		n[1] = 1 ;
	else
	{
		ft_error_before(g, "*map error");
		exit (1);
	}
}
