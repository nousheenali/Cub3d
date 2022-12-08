/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:05:40 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 09:49:56 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_valid_name(t_game *g, char *m_name)
{
	int	fd;

	if (ft_strrchr(m_name, '.'))
	{
		if (ft_strncmp(ft_strrchr(m_name, '.'), ".cub", 5)
			|| ft_strlen(m_name) == 4)
			ft_error_before(g, "Map name invalid!\n");
	}
	else
		ft_error_before(g, "Map name invalid! Map should have .cub extension\n");
	fd = open(m_name, O_RDONLY);
	if (fd < 0)
		ft_error_before(g, strerror(errno));
	close(fd);
}

void	ft_valid_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)(g->map.ht / GRID))
	{
		j = -1;
		while (++j <= (int)(g->map.wt / GRID))
		{
			if (g->map.map[i][j] != '1' && g->map.map[i][j] != '0'
				&& g->map.map[i][j] != ' ' && (g->map.map[i][j] != '\n'
				&& g->map.map[i][j] != '\0') && (g->map.map[i][j] != 'N'
				&& g->map.map[i][j] != 'S' && g->map.map[i][j] != 'E'
				&& g->map.map[i][j] != 'W'))
				ft_error_before(g, "Invalid  map content!!\n");
		}
	}
}

void	check_init_space(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j] == ' ')
			g->map.map[i][j] = 'x';
	}
}

void print_map(t_game *g)
{
	for(int i = 0; i < (int)(g->map.ht / GRID); i++)
	{
		for(int j = 0; j <= (int)(g->map.wt / GRID); j++)
		{
			printf("%c", g->map.map[i][j]);
		}
		printf("*\n");
	}
}

void	parse_map(t_game *g, char *m_name)
{
	ft_valid_name(g, m_name);
	ft_read_map(g, m_name);
	ft_valid_map(g);
	ft_valid_ply(g);
	ft_find_ply_posi(g);
	check_init_space(g);
	check_closed_walls_r(g);
	check_closed_walls_l(g);
	check_closed_walls_top(g);
	print_map(g);
	check_closed_walls_bot(g);
}
