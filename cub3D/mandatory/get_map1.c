/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:24 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/14 10:18:26 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

char	*skip_newlines(int *ct, char *ln, int fd)
{
	*ct = *ct + 1;
	free (ln);
	ln = get_next_line(fd);
	return (ln);
}

int	get_map_details(t_map *m, int fd, t_game *g)
{
	char	*ln;
	int		ct;
	int		flag;

	ln = get_next_line(fd);
	if (!ln)
		return (0);
	clear_texture(g, &ct, &flag);
	while (ln)
	{
		while (ln && ft_strcmp(ln, "\n") == 0)
			ln = skip_newlines(&ct, ln, fd);
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

char	*get_ln(char *ln, t_game *g)
{
	char	*new;
	int		i;
	int		wt;

	i = 0;
	wt = (int)g->map.wt;
	new = malloc(sizeof(char) * wt);
	while (ln[i] != '\n' && ln[i] != '\0')
	{
		new[i] = ln[i];
		i++;
	}
	while (i < wt)
		new[i++] = ' ';
	new[i] = '\0';
	free(ln);
	return (new);
}

void	store_line(int i, int j, int fd, t_game *g)
{
	while (++j < i)
		g->map.map[j] = get_ln(get_next_line(fd), g);
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
	close(fd);
}

int	ft_read_map(t_game *g, char *map_name)
{
	int		fd;
	int		i;
	int		j;
	int		ct;

	j = -1;
	fd = open(map_name, O_RDONLY);
	ft_init(&g->map);
	ct = get_map_details(&g->map, fd, g);
	close(fd);
	if (ct <= 0)
	{
		printf("Map is empty\n");
		return (1);
	}
	check_floor_ce(g);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	skip_line(ct, fd);
	store_line(i, j, fd, g);
	return (0);
}
