/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:06:41 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/06 16:07:33 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void check_closed_walls_r(t_game *g)
{
	int i = 0;
	int j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (g->map.map[++i])
	{
		j = 0;
		len = strlen(g->map.map[i]);
		while (g->map.map[i][j] == 'x')
		{
			j++;
		}
		if (g->map.map[i][j] != '1')
		{
			while (flag == 0 && (i+n) < (int)g->map.ht/64)
			{
				printf("%d %d %c\n", i, j, g->map.map[i][j]);
				a = g->map.map[i-1][j+n];
				b = g->map.map[i][j+n];
				c = g->map.map[i-1][j+n];
				if (a != '1' && b != '1' && c != '1')
					ft_error(g, "+++map error");
				else if (a == '1' && c == '1' && b != '1')
					n++;
				else if (a == '1' && b == '1' && c == '1')
					flag = 1 ;
				else
					ft_error(g, "***map error");
			}
		}
	}
}

void check_closed_walls_l(t_game *g)
{
	int i = 0;
	int j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (g->map.map[++i])
	{
		len = strlen(g->map.map[i]);
		j = len - 1;
		if (g->map.map[i][j] != '1')
		{
			while (flag == 0 && (i+n) < (int)g->map.ht/64)
			{
				a = g->map.map[i-1][j+n];
				b = g->map.map[i][j+n];
				c = g->map.map[i-1][j+n];
				if (a != '1' && b != '1' && c != '1')
					ft_error(g, "++++map error");
				else if (a == '1' && c == '1' && b != '1')
					n++;
				else if (a == '1' && b == '1' && c == '1')
					flag = 1 ;
				else
					ft_error(g, "****map error");
			}
		}
	}
}

void check_closed_walls_bot(t_game *g)
{
	int i = (int)g->map.ht/64;
	int j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (--i > 0)
	{
		j = 0;
		len = strlen(g->map.map[i]);
		while(++j < len-1)
		{
			if(g->map.map[i][j] == ' ')
			{ 
				while (flag == 0 && (i-n) > 1)
				{
					if (g->map.map[i][j + 1] == '1')
					{
						a = g->map.map[i-n][j-1];
						b = g->map.map[i-n][j];
						c = g->map.map[i-n][j + 1];
						if (a != '1' && b != '1' && c != '1')
							ft_error(g, "++map error");
						else if (a == '1' && c == '1' && b != '1')
							n++;
						else if (a == '1' && b == '1' && c == '1')
							flag = 1 ;
						else
							ft_error(g, "**map error");
				}
				}
			}
		}
	}
}

void	check_closed_walls_top(t_game *g)
{
	int i = -1, j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (g->map.map[++i])
	{
		j = 0;
		len = strlen(g->map.map[i]);
		while(++j < len-1)
		{
			if(g->map.map[i][j] == ' ')
			{ 
				while (flag == 0 && (i+n) < (int)g->map.ht/64)
				{
				if (g->map.map[i][j + 1] == '1')
				{
					a = g->map.map[i+n][j-1];
					b = g->map.map[i+n][j];
					c = g->map.map[i+n][j + 1];
					if (a != '1' && b != '1' && c != '1')
						ft_error(g, "+map error");
					else if (a == '1' && c == '1' && b != '1')
						n++;
					else if (a == '1' && b == '1' && c == '1')
						flag = 1 ;
					else
						ft_error(g, "*map error");
				}
				}
			}
		}
		// if (j == len - 1 && i == 0)
		// 	if (g->map.map[i][j-1] != '1' || g->map.map[i+1][j] != '1' || g->map.map[i][j] != '1')
		// 		ft_error(g, "-map error");
	}
}