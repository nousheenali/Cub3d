/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:50 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/12 17:08:14 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	get_floor(char *ln, t_game *g)
{
	char	**c;
	int		r;
	int		gr;
	int		b;

	if (g->map.fl || (ln[1] != ' ' && !ft_isdigit(ln[2])))
	{
		ft_error_before(g, "Invalid or duplicate entry for F\n");
		return (1);
	}
	c = ft_split(&ln[2], ',');
	r = ft_atoi(c[0]);
	gr = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	ft_2darray((void **)c);
	g->map.fl = (r << 16) + (gr << 8) + (b);
	return (0);
}

int	get_ceiling(char *ln, t_game *g)
{
	char	**c;
	int		r;
	int		gr;
	int		b;

	if (g->map.ce || (ln[1] != ' ' && !ft_isdigit(ln[2])))
	{
		ft_error_before(g, "Invalid or duplicate entry for C\n");
		return (1);
	}
	c = ft_split(&ln[2], ',');
	r = ft_atoi(c[0]);
	gr = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	ft_2darray((void **)c);
	g->map.ce = (r << 16) + (gr << 8) + (b);
	return (0);
}

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
	ln1[0] != 'S' && ln1[0] != 'E' && ln1[0] != 'W' && ln1[0] != 'F' && \
	ln1[0] != 'C' && ln1[0] != '\t')
	{
		ft_error_before(g, "Invalid map content!!");
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

void	check_floor_ce(t_game *g)
{
	if (!g->map.fl || !g->map.ce)
	{
		ft_error_before(g, "Floor or ceiling missing!!\n");
		exit (1);
	}
}
