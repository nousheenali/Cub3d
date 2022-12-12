/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:24 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/12 09:48:24 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	get_details(char *ln, t_game *g, char *ln1)
{
	if (ln1[0] == 'N' || ln1[0] == 'S' || ln1[0] == 'E' || ln1[0] == 'W')
	{
		if (ft_get_texture(g, ln1))
			ft_exit_check_line(ln, ln1);
	}
	if (ln1[0] == 'F')
	{
		if (get_floor(ln, g))
			ft_exit_check_line(ln, ln1);
	}
	else if (ln1[0] == 'C')
	{
		if (get_ceiling(ln, g))
			ft_exit_check_line(ln, ln1);
	}
	if (ln1[0] != '1' && ln1[0] != '\n' && ln1[0] != 'N' && ln1[0] != ' ' && \
	ln[0] != 'S' && ln1[0] != 'E' && ln1[0] != 'W' && ln1[0] != 'F' && \
	ln1[0] != 'C' && ln1[0] != '\t')
	{
		ft_error_before(g, "Invalid map content 123!!");
		ft_exit_check_line(ln, ln1);
	}
}

int	check_line(char *ln, t_game *g)
{
	char	*ln1;
	char	*trim;

	ln1 = malloc(sizeof(char) * strlen(ln));
	ft_strlcpy(ln1, ln, strlen(ln));
	get_details(ln, g, ln1);
	if (ln1[0] == ' ' || ln1[0] == '\t')
	{
		trim = ft_strtrim(ln1, " ");
		if (trim[0] != '1')
		{
			free(trim);
			ft_error_before(g, "Invalid map content!!");
			ft_exit_check_line(ln, ln1);
		}
		free(trim);
	}
	if (ln1[0] == 'N' || ln1[0] == 'S' || ln1[0] == 'E'
		|| ln1[0] == 'W' || ln1[0] == 'F' || ln1[0] == 'C')
	{
		free(ln1);
		return (1);
	}
	free(ln1);
	return (0);
}

int	get_map_details(t_map *m, int fd, t_game *g)
{
	char	*ln;
	int		ct;
	int		flag;

	ln = get_next_line(fd);
	clear_texture(g, &ct, &flag, ln);
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
		ft_error_exit(g, "Map is empty\n");
	check_floor_ce(g);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	skip_line(ct, fd);
	while (++j < i)
		g->map.map[j] = get_ln(get_next_line(fd));
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
	close(fd);
	return (0);
}
