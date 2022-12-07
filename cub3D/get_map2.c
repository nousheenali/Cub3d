/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:50 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/07 12:57:02 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	get_floor(char *ln, t_map *m)
{
	char	**c;
	int		r;
	int		g;
	int		b;

	c = ft_split(&ln[2], ',');
	r = ft_atoi(c[0]);
	g = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	m->fl = (r << 16) + (g << 8) + (b);
}

void	get_ceiling(char *ln, t_map *m)
{
	char	**c;
	int		r;
	int		g;
	int		b;

	c = ft_split(&ln[2], ',');
	r = ft_atoi(c[0]);
	g = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	m->ce = (r << 16) + (g << 8) + (b);
}

void	ft_get_texture(t_game *g, char *ln)
{
	if (ln[strlen(ln) - 1] == '\n')
		ln[strlen(ln) - 1] = '\0';
	if (ln[0] == 'N')
		g->wall1.path = &ln[3];
	else if (ln[0] == 'S')
		g->wall2.path = &ln[3];
	else if (ln[0] == 'W')
		g->wall3.path = &ln[3];
	else if (ln[0] == 'E')
		g->wall4.path = &ln[3];
}
