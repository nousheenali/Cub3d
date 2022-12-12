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

int	get_east_west(t_game *g, char *ln)
{
	char	*trim;

	trim = ft_strtrim(&ln[3], " \t");
	if (ln[0] == 'W' && ln[1] == 'E')
	{
		if (g->wall1.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Invalid or duplicate Entry!!\n");
			return (1);
		}
		g->wall1.path = trim;
	}
	else if (ln[0] == 'E' && ln[1] == 'A')
	{
		if (g->wall2.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Invalid or duplicate Entry!!\n");
			return (1);
		}
		g->wall2.path = trim;
	}
	return (0);
}

int	ft_get_texture(t_game *g, char *ln)
{
	char	*trim;

	if (ln[0] == 'W' || ln[0] == 'E')
	{
		if (get_east_west(g, ln))
			return (1);
	}
	else if (ln[0] == 'S' && ln[1] == 'O')
	{
		trim = ft_strtrim(&ln[3], " \t");
		if (g->wall3.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Invalid or duplicate Entry!!\n");
			return (1);
		}
		g->wall3.path = ft_strdup(&ln[3]);
	}
	else if (ln[0] == 'N' && ln[1] == 'O')
	{
		trim = ft_strtrim(&ln[3], " \t");
		if (g->wall4.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Invalid or duplicate Entry!!\n");
			return (1);
		}
		g->wall4.path = ft_strdup(&ln[3]);
	}
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
