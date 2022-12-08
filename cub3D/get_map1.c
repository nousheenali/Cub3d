/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:24 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 11:38:34 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	check_line(char *ln, t_game *g)
{
	char	*ln1;

	ln1 = malloc(sizeof(char) * strlen(ln));
	ft_strlcpy(ln1, ln, strlen(ln));
	if (ln1[0] == 'N' || ln1[0] == 'S' || ln1[0] == 'E' || ln1[0] == 'W')
		ft_get_texture(g, ln1);
	if (ln1[0] == 'F')
		get_floor(ln, g);
	else if (ln1[0] == 'C')
		get_ceiling(ln, g);
	if (ln1[0] == 'N' || ln1[0] == 'S' || ln1[0] == 'E'
		|| ln1[0] == 'W' || ln1[0] == 'F' || ln1[0] == 'C')
	{
		free(ln1);
		return (1);
	}
	else if (ln1[0] != '1' && ln1[0] != '\n' && ln1[0] != ' ')
		ft_error_before(g, "Invalid map content!!");
	free(ln1);
	return (0);
}

int	get_map_size(t_map *m, char *ln, int ct)
{
	if (m->wt < (double)ft_strlen(ln))
		m->wt = ft_strlen(ln);
	m->ht++;
	return (ct - 1);
}

int	get_map_details(t_map *m, int fd, t_game *g)
{
	char	*ln;
	int		ct;
	int		flag;

	ln = get_next_line(fd);
	clear_texture(g, &ct, &flag);
	while (ln)
	{
		while (ln && ft_strcmp(ln, "\n") == 0)
		{
			ct++;
			free (ln);
			ln = get_next_line(fd);
		}
		while (ln && ft_strcmp(ln, "\n"))
		{
			flag = check_line(ln, g);
			if (flag == 0)
				ct = get_map_size(m, ln, ct);
			ct++;
			free (ln);
			ln = get_next_line(fd);
		}
	}
	return (ct + 1);
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
	free(ln);
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
	ct = get_map_details(&g->map, fd, g);
	check_floor_ce(g);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	skip_line(ct, fd);
	while (++j < i)
	{
		ln = get_next_line(fd);
		g->map.map[j] = get_ln(ln);
	}
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
	close(fd);
}