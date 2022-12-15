/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:08:22 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/14 10:33:13 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_clear_buffer(unsigned int **b, t_game *g)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < g->win_ht)
	{
		j = -1;
		while (++j < g->win_wt)
		{
			b[i][j] = 0;
		}
	}
}

void	ft_populate_buffer(t_game *g, double proj_h, int x)
{
	int	top;
	int	bottom;
	int	y;

	top = (int)(g->win_ht / 2) - (int)(proj_h / 2);
	if (top < 0)
		top = 0;
	bottom = (int)(g->win_ht / 2) + (int)(proj_h / 2);
	if (bottom >= g->win_ht)
		bottom = g->win_ht - 1;
	y = (top - 1);
	while (++y < bottom)
		g->buffer[y][x] = 0x8545e6;
}

int	ft_ceiling(unsigned int	**buffer, int i, int k)
{
	if (i == 0)
		return (1);
	while (--i > -1)
	{
		if (buffer[i][k] != 0)
			return (0);
	}
	return (1);
}

int	ft_floor(unsigned int **buffer, int i, int k, t_game *g)
{
	if (i == 0)
		return (1);
	while (++i < g->win_ht)
	{
		if (buffer[i][k] != 0)
			return (0);
	}
	return (1);
}
