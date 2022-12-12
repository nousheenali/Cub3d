/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:20:17 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/12 09:33:26 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	contain_walls_or_spaces_only(char *temp)
{
	int	j;

	j = 0;
	while (temp[j])
	{
		if (temp[j] != '1' && temp[j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

void	check_closed_walls(t_game *g)
{
	int		i;
	int		flag;
	char	*temp;

	i = 0;
	flag = 0;
	while (g->map.map[i])
	{
		temp = ft_strtrim(g->map.map[i], "x");
		if (temp[0] != '1' || temp[ft_strlen(temp) - 1] != '1')
			flag = 1;
		if (i == 0)
			if (contain_walls_or_spaces_only(temp))
				flag = 1;
		if (i == ((int)g->map.ht / 64 - 1))
			if (contain_walls_or_spaces_only(temp))
				flag = 1;
		free(temp);
		if (flag == 1)
		{
			ft_error_before(g, "Map not enclosed by walls!!!");
			exit(1);
		}
		i++;
	}
}

void	check_before_space(t_game *g, int i, int j)
{
	if (i + 1 < (int)g->map.ht / 64)
		if (g->map.map[i + 1][j] != ' ' && g->map.map[i + 1][j] != '1')
			ft_error_exit(g, "Map not enclosed by walls!!!");
	if (i - 1 >= 0)
		if (g->map.map[i - 1][j] != ' ' && g->map.map[i - 1][j] != '1')
			ft_error_exit(g, "Map not enclosed by walls!!!");
	if (j + 1 < (int)g->map.wt / 64)
		if (g->map.map[i][j + 1] != ' ' && g->map.map[i][j + 1] != '1')
			ft_error_exit(g, "Map not enclosed by walls!!!");
	if (j - 1 >= 0)
		if (g->map.map[i][j - 1] != ' ' && g->map.map[i][j - 1] != '1')
			ft_error_exit(g, "Map not enclosed by walls!!!");
}

void	check_wall_all_dir(t_game *g)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (g->map.map[i])
	{
		j = 0;
		temp = g->map.map[i];
		while (g->map.map[i][j])
		{
			if (temp[j] == ' ')
			{	
				check_before_space(g, i, j);
			}
			j++;
		}
		i++;
	}
}

void	check_for_wall(t_vec t, t_game *g)
{
	int	x;
	int	y;

	x = (int)(t.x / GRID);
	y = (int)(t.y / GRID);
	if (g->map.map[y][x] != '1')
	{
		g->init_dist.x = t.x;
		g->init_dist.y = t.y;
	}
}
