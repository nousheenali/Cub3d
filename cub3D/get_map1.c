/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:24 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 15:31:19 by sfathima         ###   ########.fr       */
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
	clear_texture(g, &ct, &flag);
	if (!ln)
		return (0);
	while (ln)
	{
		while (ln && ft_strcmp(ln, "\n") == 0)
			ln = skip_newlines(&ct, ln, fd);
		while (ln && ft_strcmp(ln, "\n"))
		{
			flag = check_line(ln, g, fd);
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

void	store_map(t_game *g, int i, int j, int fd)
{
	char	*ln;

	while (++j < i)
	{
		ln = get_next_line(fd);
		g->map.map[j] = get_ln(ln);
	}
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
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
	if (ct <= 0)
	{
		printf("Map is empty\n");
		close(fd);
		return (1);
	}
	check_floor_ce(g, fd);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	skip_line(ct, fd);
	store_map(g, i, j, fd);
	close(fd);
	return (0);
}
