/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:24 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/07 13:33:56 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	check_line(char *ln, t_game *g)
{
	if (ln[0] == 'N' || ln[0] == 'S' || ln[0] == 'E' || ln[0] == 'W')
		ft_get_texture(g, ln);
	else if (ln[0] == 'F')
		get_floor(ln, &g->map);
	else if (ln[0] == 'C')
		get_ceiling(ln, &g->map);
	if (ln[0] == 'N' || ln[0] == 'S' || ln[0] == 'E'
		|| ln[0] == 'W' || ln[0] == 'F' || ln[0] == 'C')
		return (1);
	return (0);
}

int	get_map_size(t_map *m, char *ln, int ct)
{
	if (m->wt < (double)ft_strlen(ln))
		m->wt = ft_strlen(ln);
	m->ht++;
	return (ct - 1);
}

void	clear_texture(t_game *g)
{
	g->wall1.path = NULL;
	g->wall2.path = NULL;
	g->wall3.path = NULL;
	g->wall4.path = NULL;
}

int	get_map_details(t_map *m, int fd, t_game *g)
{
	char	*ln;
	int		ct;
	int		flag;

	ln = get_next_line(fd);
	ct = 0;
	flag = 0;
	clear_texture(g);
	while (ln)
	{
		while (ln && ft_strcmp(ln, "\n") == 0)
		{
			ct++;
			ln = get_next_line(fd);
		}
		while (ln && ft_strcmp(ln, "\n"))
		{
			flag = check_line(ln, g);
			if (flag == 0)
				ct = get_map_size(m, ln, ct);
			ln = get_next_line(fd);
			ct++;
		}
	}
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

void	ft_print_map(t_game *g)
{
	for(int i = 0; i < (int)(g->map.ht / GRID); i++)
	{
		for (int j = 0; j <= (int)(g->map.wt / GRID); j++)
		{
			printf("%c",  g->map.map[i][j]);
		}
		printf("\n");
	}
}

void	check_floor_ce(t_game *g)
{
	if (!g->map.fl || !g->map.ce)
		ft_error_before("Map content missing!!\n");
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
	ct = get_map_details(&g->map, fd, g);
	check_floor_ce(g);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	while (--ct >= 0)
		ln = get_next_line(fd);
	while (++j < i)
	{
		g->map.map[j] = get_ln(get_next_line(fd));
	}
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
	close(fd);
}
