/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:03:29 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/16 13:21:33 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	move_r(t_game *g, t_vec t, char c)
{
	if (c == 'r')
	{
		t.a = g->angle + 1;
		t.a = limit_ang(t.a);
		g->angle = t.a;
	}
	if (c == 'l')
	{
		t.a = g->angle - 1;
		t.a = limit_ang(t.a);
		g->angle = t.a;
	}
}

int	mouse_events(int x, int y, t_game *g, t_vec t)
{
	if (x < g->win_wt / 2 && (y > 0 && y < g->win_ht))
		move_r(g, t, 'r');
	else
		move_r(g, t, 'l');
	mlx_mouse_move(g->win, g->win_wt / 2, g->win_wt / 2);
	ft_start(g);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		printf("Wrong no. of arg!! Try ./cub3D map");
		return (1);
	}
	if (parse_map(&g, argv[1]))
		return (1);
	ft_init_variables(&g);
	if (ft_convert_xpm_to_img(&g))
		ft_close(&g);
	ft_start(&g);
	mlx_hook(g.win, 2, 1L << 0, &ft_button, &g);
	mlx_hook(g.win, 17, 0, ft_close, &g);
	mlx_hook(g.win, 6, 0, &mouse_events, &g);
	mlx_loop(g.mlx);
}
