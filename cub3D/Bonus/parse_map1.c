/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:05:40 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/14 10:23:32 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	ft_valid_name(char *m_name)
{
	int	fd;

	if (ft_strrchr(m_name, '.'))
	{
		if (ft_strncmp(ft_strrchr(m_name, '.'), ".cub", 5)
			|| ft_strlen(m_name) == 4)
		{
			printf("Map name invalid!\n");
			return (1);
		}
	}
	else
	{
		printf("Map name invalid! Map should have .cub extension\n");
		return (1);
	}
	fd = open(m_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Invalid file\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_valid_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)(g->map.ht / GRID))
	{
		j = -1;
		while (g->map.map[i][++j])
		{
			if (g->map.map[i][j] != '1' && g->map.map[i][j] != '0'
				&& g->map.map[i][j] != ' ' && (g->map.map[i][j] != '\n'
				&& g->map.map[i][j] != '\0') && (g->map.map[i][j] != 'N'
				&& g->map.map[i][j] != 'S' && g->map.map[i][j] != 'E'
				&& g->map.map[i][j] != 'W'))
			{
				ft_error_before(g, "Invalid  map content!!\n");
				return (1);
			}
		}
	}
	return (0);
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

// void	print_map(t_game *g)
// {
// 	int	i =0;
// 	int	j = 0;

// 	while (i < (int)(g->map.ht / GRID))
// 	{
// 		j = 0;
// 		while (g->map.map[i][j])
// 		{
// 			printf("%c", g->map.map[i][j]);
// 			j++;
// 		}
// 		printf("*\n");
// 		i++;
// 	}
// }

void	ft_2darray(void **c)
{
	int	i;

	i = -1;
	if (c)
	{
		while (c[++i])
			free(c[i]);
		free(c);
	}
}

int	parse_map(t_game *g, char *m_name)
{
	if (ft_valid_name(m_name))
		return (1);
	if (ft_read_map(g, m_name))
		return (1);
	if (ft_valid_map(g))
		return (1);
	ft_valid_ply(g);
	ft_find_ply_posi(g);
	check_closed_walls(g);
	check_wall_all_dir(g);
	return (0);
}
