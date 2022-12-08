/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:06:41 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 16:42:10 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	check_closed_walls_r(t_game *g)
{
	int		i;
	int		j;
	int		n[2];

	set_value(&i, &n[0], &n[1], 0);
	while (g->map.map[++i])
	{
		j = 0;
		while (g->map.map[i][j] == 'x')
			j++;
		if (g->map.map[i][j] != '1')
		{
			while (n[1] == 0 && (i + n[0]) < (int)g->map.ht / 64)
			{
				if (g->map.map[i - 1][j + n[0]] == '1' && g->map.map[i + 1] \
				[j + n[0]] == '1' && g->map.map[i][j + n[0]] != '1')
					n[0]++;
				else if (g->map.map[i - 1][j + n[0]] == '1' && g->map.map[i] \
				[j + n[0]] == '1' && g->map.map[i - 1][j + n[0]] == '1')
					n[1] = 1 ;
				else
				{
					ft_error_before(g, "***map error");
					exit(1);
				}
			}
		}
	}
}

void	check_closed_walls_l(t_game *g)
{
	int	i;
	int	j;
	int	n;
	int	flag;

	set_value(&i, &n, &flag, 0);
	while (g->map.map[++i])
	{
		j = strlen(g->map.map[i]) - 1;
		if (g->map.map[i][j] != '1')
		{
			while (flag == 0 && (i + n) < (int)g->map.ht / 64)
			{
				if (g->map.map[i - 1][j + n] == '1' && g->map.map[i + 1] \
				[j + n] == '1' && g->map.map[i][j + n] != '1')
					n++;
				else if (g->map.map[i - 1][j + n] == '1' && g->map.map[i] \
				[j + n] == '1' && g->map.map[i - 1][j + n] == '1')
					flag = 1 ;
				else
				{
					ft_error_before(g, "****map error");
					exit (1);
				}
			}
		}
	}
}	

void	ft_check(t_game *g, int i, int j, int *n)
{
	if (j == ft_strlen(g->map.map[i]))
	{
		if (g->map.map[i][j - 1] != '1' || g->map.map[i][j] != '1')
		{
			ft_error_before(g, "*map error");
			exit (1);
		}
	}
	if (g->map.map[i - n[0]][j - 1] == '1' && g->map.map[i - n[0]][j + 1] \
	== '1' && g->map.map[i - n[0]][j] != '1')
		n[0]++;
	else if (g->map.map[i - n[0]][j - 1] == '1' && g->map.map[i - n[0]][j] \
	== '1' && g->map.map[i - n[0]][j + 1] == '1')
		n[1] = 1 ;
	else
	{
		ft_error_before(g, "**map error");
		exit (1);
	}
}

void	check_closed_walls_bot(t_game *g)
{
	int	i;
	int	j;
	int	n[2];

	set_value1(&i, &n[0], &n[1], g);
	while (--i >= 0)
	{
		j = 0;
		while (++j < ft_strlen(g->map.map[i]))
		{
			if (g->map.map[i][j] != '1')
			{
				while (n[1] == 0 && (i - n[0]) > 0)
				{
					if (g->map.map[i][j + 1] == '1')
					{
						ft_check(g, i, j, n);
					}
					else
						n[0]++;
				}
			}
			check_end(g, i, j);
		}
	}
}

void	check_closed_walls_top(t_game *g)
{
	int	i;
	int	j;
	int	n[2];

	set_value(&i, &n[0], &n[1], 1);
	while (g->map.map[++i])
	{
		j = -1;
		while (++j < (ft_strlen(g->map.map[i])))
		{
			while (g->map.map[i][j] == 'x')
				j++;
			if (g->map.map[i][j] != '1')
			{
				while (n[1] == 0 && (i + n[0]) < (int)g->map.ht / 64)
				{
					if (g->map.map[i][j + 1] == '1')
						ft_check1(g, i, j, n);
				}
			}
			if (i == 0 && (g->map.map[i][j] == '0'))
			{
				ft_error_before(g, "-++*map error");
				exit (1);
			}
			else
				n[0]++;
		}
		if (j == (ft_strlen(g->map.map[i]) - 1) && i == 0)
		{
			if (g->map.map[i][j - 1] != '1' || g->map.map[i + 1][j] != '1'
				|| g->map.map[i][j] != '1')
			{
				ft_error(g, "-*map error");
				exit(1);
			}
		}
	}
}
