#include "raycaster.h"

double ft_get_projected_height(t_game *g, double alpha, t_vec hit, double beta)
{
	double y_dist;
	double x_dist;
	double ray_length;
	double proj_h;

	x_dist = hit.x;
	y_dist = hit.y;
	if (x_dist < y_dist)
		ray_length = x_dist * cos(ft_convert_deg_to_rad(beta));//correcting fish eye
	else
		ray_length = y_dist * cos(ft_convert_deg_to_rad(beta)); //correcting fish eye
	//ray_length is the actual length of the ray when it hits the wall
	proj_h = (GRID * g->dist_proj) / ray_length;
	return (proj_h);
}

void ft_populate_buffer(t_game *g, double proj_h, int x)
{
	int top;
	int bottom;
	int y;
	
	top = (g->win_ht / 2) - (int)(proj_h / 2);
	if (top < 0)
		top = 0;
	bottom = (g->win_ht / 2) + (int)(proj_h / 2);
	if (bottom >= g->win_ht)
		bottom = g->win_ht - 1;
	y = (top - 1);
	while (++y < bottom)
		g->buffer[y][x] = 0x8545e6;

}
// void	do_raycast(t_game *g, int x)
// {
// 	double	r;
// 	int		y;
// 	int		end;
// 	int		begin;
// 	char	*dst;

// 	r = deg_rad(g->pos.vc.a) - g->angle;
// 	if (r > deg_rad(359.00))
// 		r -= deg_rad(360.00);
// 	else if (r < deg_rad(0.00))
// 		r += deg_rad(360.00);
	// g->dist_proj = g->dist_proj * cos(r);
	// raycast->h_line = (int)(GRID * (1.00 * g->win_ht)) / g->init_dist;
	// begin = (WIN_H / 2) - (int)(raycast->h_line / 2.00);
	// if (begin < 0)
	// 	begin = 0;
	// end = (WIN_H / 2) + (int)(raycast->h_line / 2.00);
	// if (end >= WIN_H)
	// 	end = WIN_H - 1;
	// y = (begin - 1);
	// while (++y < end)
	// {
	// 	if ((y > -1 && y < WIN_H) && (x > -1 && x < WIN_W))
	// 		raycast->main->buffer[y][x] = 0x5d478b;
	// 	raycast->main->re_buf = 1;
	// }
// }

//to calculate the camare plane
void start_game(t_game *g)
{
	int i;
	double alpha;
	double beta;
	t_vec hit;
	double proj_h;//projected height
	// double x,y;

	i = -1;
	alpha = g->angle + (g->fov / 2); // angle to rightmost ray in degrees
	beta = g->fov/2;
	while(++i < g->win_wt)
	{
		hit.y = ft_y_axis_hit(g, alpha);
		hit.x = ft_x_axis_hit(g, alpha);
		proj_h = ft_get_projected_height(g, alpha, hit, beta);
		ft_populate_buffer(g, proj_h, i);
		alpha = alpha - g->angle_btw_rays;
		if(alpha <= g->angle)
			beta = beta + g->angle_btw_rays;
		else
			beta = beta - g->angle_btw_rays;
		// do_raycast(g, i);
	}
}

int ft_ceiling(unsigned int	**buffer, int i, int k)
{
	if (i == 0)
		return (1);
	while (--i > -1)
	{
		if (buffer[i][k] != 0)
			return (0);
	}
	return (1);
}

int ft_floor(unsigned int **buffer, int i, int k, t_game *g)
{
	if (i == 0)
		return (1);
	while (++i < g->win_ht)
	{
		if (buffer[i][k] != 0)
			return (0);
	}
	return (1);
}

void ft_start(t_game *g)
{

	int	i;
	int	k;

	i = -1;
	start_game(g);
	while (++i < g->win_ht)
	{
		k = -1;
		while (++k < g->win_wt)
		{
			if (ft_ceiling(g->buffer, i, k))
				g->data[i * g->win_wt + k] = 0x00FFFF;
			else if (ft_floor(g->buffer, i, k, g))
				g->data[i * g->win_wt + k] = 0x228B22;
			else
			g->data[i * g->win_wt + k] = g->buffer[i][k];
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}
