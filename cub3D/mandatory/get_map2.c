/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:50 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/16 12:37:06 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	get_floor(char *ln, t_game *g)
{
	char	**c;
	int		r;
	int		gr;
	int		b;

	if (g->map.fl || (ln[1] != ' ' && !ft_isdigit(ln[2])) \
	|| ft_count_char(&ln[2], ',') > 2)
	{
		ft_error_before(g, "Error: Invalid or duplicate entry for F\n");
		return (1);
	}
	c = ft_split(&ln[2], ',');
	if (ceiling_floor_tests(c, g))
		return (1);
	r = ft_atoi_c(c[0]);
	gr = ft_atoi_c(c[1]);
	b = ft_atoi_c(c[2]);
	ft_2darray((void **)c);
	if (r < 0 || gr < 0 || b < 0 || r > 255 || gr > 255 || b > 255)
	{
		ft_error_before(g, "Error: Invalid entry for F\n");
		return (1);
	}
	g->map.fl = (r << 16) + (gr << 8) + (b);
	return (0);
}

int	get_ceiling(char *ln, t_game *g)
{
	char	**c;
	int		r;
	int		gr;
	int		b;

	if (g->map.ce || (ln[1] != ' ' && !ft_isdigit(ln[2])) \
	|| ft_count_char(&ln[2], ',') > 2)
	{
		ft_error_before(g, "Error: Invalid or duplicate entry for C\n");
		return (1);
	}
	c = ft_split(&ln[2], ',');
	if (ceiling_floor_tests(c, g))
		return (1);
	r = ft_atoi_c(c[0]);
	gr = ft_atoi_c(c[1]);
	b = ft_atoi_c(c[2]);
	if (r < 0 || gr < 0 || b < 0 || r > 255 || gr > 255 || b > 255)
	{
		ft_error_before(g, "Error: Invalid entry for C\n");
		return (1);
	}
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
	ln1[0] != 'C')
	{
		ft_error_before(g, "Error: Invalid map content!!!\n");
		ft_exit_check_line(ln, ln1);
	}
}

int	check_line(char *ln, t_game *g)
{
	char	*ln1;
	char	*trim;

	ln1 = malloc(sizeof(char) * strlen(ln) + 1);
	ft_strlcpy(ln1, ln, strlen(ln) + 1);
	get_details(ln, g, ln1);
	if (ln1[0] == ' ')
	{
		trim = ft_strtrim(ln1, " ");
		if (trim[0] != '1')
		{
			free(trim);
			ft_error_before(g, "Error: Invalid map content!!\n");
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
		ft_error_before(g, "Error: Floor or ceiling missing!!\n");
		exit (1);
	}
}
