/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:25:08 by nali              #+#    #+#             */
/*   Updated: 2022/12/06 14:59:39 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

/*	rayDirX > 0 when angle <90 or angle>270
	rayDirY < 0 when angle >180 or angle<360 */
int	ft_get_texture_x(t_game *g, t_vec dist, t_vec raydir)
{
	double	wallx;
	int		texx;

	if (g->side == 0)
		wallx = g->init_dist.y - (dist.x * raydir.y);
	else
		wallx = g->init_dist.x + (dist.y * raydir.x);
	wallx = wallx / TEXWIDTH;
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)(TEXWIDTH));
	if (g->side == 0 && raydir.x > 0)
		texx = TEXWIDTH - texx - 1;
	if (g->side == 1 && raydir.y < 0)
		texx = TEXWIDTH - texx - 1;
	return (texx);
}

int	get_pixel_color(t_game *g, int x, int y)
{
	char			*dst;
	unsigned int	color;

	if (g->side == 1)
	{
		dst = g->wall1.addr + (y * g->wall1.line + (x * (g->wall1.bpp / 8)));
		color = *(unsigned int *)dst;
	}
	else if (g->side == 2)
	{
		dst = g->wall2.addr + (y * g->wall2.line + (x * (g->wall2.bpp / 8)));
		color = *(unsigned int *)dst;
	}
	else if (g->side == 3)
	{
		dst = g->wall3.addr + (y * g->wall3.line + (x * (g->wall3.bpp / 8)));
		color = *(unsigned int *)dst;
	}
	else
	{
		dst = g->wall4.addr + (y * g->wall4.line + (x * (g->wall4.bpp / 8)));
		color = *(unsigned int *)dst;
	}
	return (color);
}

/*	Cast the texture coordinate to integer, and mask with 
	(texHeight - 1) in case of overflow
	tex_y = (int)texPos & (TEXHEIGHT - 1);*/
void	ft_render_texture(t_game *g, int texx, double step, int x)
{
	int		top;
	int		bottom;
	int		y;
	double	texpos;
	int		texy;

	ft_get_proj_top_bottom(g, &top, &bottom);
	texpos = (top - g->win_ht / 2 + g->proj_h / 2) * step;
	y = (top - 1);
	while (++y < bottom)
	{
		texy = (int)texpos & (TEXHEIGHT - 1);
		texpos += step;
		g->buffer[y][x] = get_pixel_color(g, texx, texy);
	}
}

/*  step = 1.0 * TEXHEIGHT / g->proj_h;
	for 1 unit increase in proj_h, by how much unit should texture step increase
	(texture step size)/(texture height) = (proj step size)/(projection height)
*/
void	ft_texture(t_game *g, double alpha, t_vec dist, int x)
{
	int		texx;
	t_vec	raydir;
	double	step;

	ft_get_ray_direction(alpha, &raydir);
	texx = ft_get_texture_x(g, dist, raydir);
	get_side(g, raydir);
	step = 1.0 * TEXHEIGHT / g->proj_h;
	ft_render_texture(g, texx, step, x);
}
