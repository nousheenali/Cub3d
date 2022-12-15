/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:24:18 by nali              #+#    #+#             */
/*   Updated: 2022/12/14 10:21:49 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	ft_wall_1_image(t_game *g)
{
	char	*wall;
	int		pos[2];

	wall = g->wall1.path;
	g->wall1.img = mlx_xpm_file_to_image(g->mlx, wall, &pos[0], &pos[1]);
	if (!(g->wall1.img))
	{
		printf("Unable to load xpm image.\n");
		return (1);
	}
	g->wall1.addr = mlx_get_data_addr(g->wall1.img, \
	&g->wall1.bpp, &g->wall1.line, &g->wall1.endian);
	return (0);
}

int	ft_wall_2_image(t_game *g)
{
	char	*wall;
	int		pos[2];

	wall = g->wall2.path;
	g->wall2.img = mlx_xpm_file_to_image(g->mlx, wall, &pos[0], &pos[1]);
	if (!(g->wall2.img))
	{
		printf("Unable to load xpm image.\n");
		return (1);
	}
	g->wall2.addr = mlx_get_data_addr(g->wall2.img, \
	&g->wall2.bpp, &g->wall2.line, &g->wall2.endian);
	return (0);
}

int	ft_wall_3_image(t_game *g)
{
	char	*wall;
	int		pos[2];

	wall = g->wall3.path;
	g->wall3.img = mlx_xpm_file_to_image(g->mlx, wall, &pos[0], &pos[1]);
	if (!(g->wall3.img))
	{
		printf("Unable to load xpm image.\n");
		return (1);
	}
	g->wall3.addr = mlx_get_data_addr(g->wall3.img, \
	&g->wall3.bpp, &g->wall3.line, &g->wall3.endian);
	return (0);
}

int	ft_wall_4_image(t_game *g)
{
	char	*wall;
	int		pos[2];

	wall = g->wall4.path;
	g->wall4.img = mlx_xpm_file_to_image(g->mlx, wall, &pos[0], &pos[1]);
	if (!(g->wall4.img))
	{
		printf("Unable to load xpm image.\n");
		return (1);
	}
	g->wall4.addr = mlx_get_data_addr(g->wall4.img, \
	&g->wall4.bpp, &g->wall4.line, &g->wall4.endian);
	return (0);
}

int	ft_convert_xpm_to_img(t_game *g)
{
	if (ft_wall_1_image(g))
		return (1);
	if (ft_wall_2_image(g))
		return (1);
	if (ft_wall_3_image(g))
		return (1);
	if (ft_wall_4_image(g))
		return (1);
	return (0);
}
