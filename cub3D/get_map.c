/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:24 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/06 16:13:58 by sfathima         ###   ########.fr       */
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

int	get_map_size(t_map *m, int fd)
{
	char	*ln;
	int		ct;

	ln = get_next_line(fd);
	ct = 0;
	while (ft_strcmp(ln, "\n"))
	{
		ln = get_next_line(fd);
		ct++;
	}
	while (!ft_strcmp(ln, "\n"))
	{
		ln = get_next_line(fd);
		if (ln[0] == 'F')
			get_floor(ln, m);
		ct++;
	}
	while (ft_strcmp(ln, "\n"))
	{
		ln = get_next_line(fd);
		if (ln[0] == 'C')
			get_ceiling(ln, m);
		ct++;
	}
	while (!ft_strcmp(ln, "\n"))
	{
		ln = get_next_line(fd);
		ct++;
	}
	m->wt = ft_strlen(ln);
	while (ln)
	{
		ln = get_next_line(fd);
		if (ln && m->wt < (double)ft_strlen(ln))
			m->wt = ft_strlen(ln);
		m->ht++;
	}
	close(fd);
	return (ct);
}

char	*get_ln(char *ln)
{
	char	*new;
	int		i;

	i = -1;
	new = malloc(sizeof(char) * ft_strlen(ln));
	while (ln[++i] != '\n' && ln[i] != '\0')
	{
		new[i] = ln[i];
	}
	new[i] = '\0';
	return (new);
}

void	ft_read_map(t_game *g, char *map_name)
{
	int		fd;
	int		i;
	int		j;
	int		ct;
	char	*ln;

	j = -1;
	fd = open(map_name, O_RDONLY);
	ft_init(&g->map);
	ct = get_map_size(&g->map, fd);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	while (--ct > 0)
		ln = get_next_line(fd);
	while (++j < i)
	{
		g->map.map[j] = get_ln(get_next_line(fd));
	}
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
	close(fd);
}
