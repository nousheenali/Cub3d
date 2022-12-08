/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:50 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 10:52:49 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	get_floor(char *ln, t_game *g)
{
	char	**c;
	int		r;
	int		gr;
	int		b;

	c = ft_split(&ln[2], ',');
	r = ft_atoi(c[0]);
	gr = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	if (g->map.fl)
		ft_error_before(g, "Wrong map content!!\n");
	g->map.fl = (r << 16) + (gr << 8) + (b);
}

void	get_ceiling(char *ln, t_game *g)
{
	char	**c;
	int		r;
	int		gr;
	int		b;

	c = ft_split(&ln[2], ',');
	r = ft_atoi(c[0]);
	gr = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	if (g->map.ce)
		ft_error_before(g, "Wrong map content!!\n");
	g->map.ce = (r << 16) + (gr << 8) + (b);
}

void	ft_get_texture(t_game *g, char *ln)
{
	if (ln[0] == 'W')
	{
		if (g->wall1.path)
			ft_error_before(g, "Wrong map content!!\n");
		g->wall1.path = ft_strdup(&ln[3]);
	}
	else if (ln[0] == 'E')
	{
		if (g->wall2.path)
			ft_error_before(g, "Wrong map content!!\n");
		g->wall2.path = ft_strdup(&ln[3]);
	}
	else if (ln[0] == 'S')
	{
		if (g->wall3.path)
			ft_error_before(g, "Wrong map content!!\n");
		g->wall3.path = ft_strdup(&ln[3]);
	}
	else if (ln[0] == 'N')
	{
		if (g->wall4.path)
			ft_error_before(g, "Wrong map content!!\n");
		g->wall4.path = ft_strdup(&ln[3]);
	}
}

void	check_floor_ce(t_game *g)
{
	if (!g->map.fl || !g->map.ce)
		ft_error_before(g, "Map content missing!!\n");
}

void	clear_texture(t_game *g, int *ct, int *flag)
{
	*ct = 0;
	*flag = 0;
	g->wall1.path = NULL;
	g->wall2.path = NULL;
	g->wall3.path = NULL;
	g->wall4.path = NULL;
	g->map.fl = 0;
	g->map.ce = 0;
}
