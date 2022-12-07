/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:53:47 by nali              #+#    #+#             */
/*   Updated: 2022/12/07 09:09:19 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define GRID 64
# define PI 3.14159265359
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct s_vec
{
	double	x;
	double	y;
	double	a;
}				t_vec;

typedef struct s_axis
{
	double	x;
	double	y;
}t_axis;

typedef struct s_pos
{
	t_axis	ax;
	t_vec	vc;
}t_pos;

typedef struct s_map
{
	char			**map;
	double			ht;
	double			wt;
	unsigned int	fl;
	unsigned int	ce;
}t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_data;

typedef struct  s_game
{
	void	*mlx;		//mlx
	void	*win;

	int		win_ht;		//screen
	int		win_wt;

	void	*img;		//mlx_image
	int		*data;
	int		bits;
	int		lines;
	int		endian;

	t_map	map;		//contains map details
	t_pos	pos;		//contains ply posi and direc

	unsigned int	**buffer;	//for colors
	
	double proj_h;
	int side;
	double 	fov;	//ray
	int		n_rays;
	double	angle;
	double angle_btw_rays;

	// double map_height;
	// double map_width;
	t_vec *hit;
	t_vec init_dist;
	double dist_proj;	//distance to proj palne
	t_data wall1; //wall textures
	t_data 	wall2;
	t_data	wall3;
	t_data	wall4;
}t_game;

//get_map
void	ft_read_map(t_game *g, char *map_name);
//hit
double	ft_y_axis_hit(t_game *g, float alpha);
double	ft_x_axis_hit(t_game *g, float alpha);
//init
void	ft_init_variables(t_game *g);
void	ft_create_buffer(t_game *g);
void	ft_init(t_map *m);
//raycaster
void	ft_start(t_game *g);
void	start_game(t_game *g);
void	fill_buf(t_game *g);
//main
double	ft_convert_deg_to_rad(double deg);
//move
int		ft_button(int key, t_game *g);
int		ft_close(t_game *g);
//parse_map
void	parse_map(t_game *g, char *m_name);
void	ft_valid_name(char *m_name);
void	ft_valid_map(t_game *g);
void	check_closed_walls(t_game *g);
void check_closed_walls_r(t_game *g);
void check_closed_walls_l(t_game *g);
void check_closed_walls_bot(t_game *g);
void	check_closed_walls_top(t_game *g);

//error
void	ft_error(t_game *g, char *msg);
void ft_error_before(char *msg);

//load_textures
int		ft_convert_xpm_to_img(t_game *g);
//ft_texture
void	ft_texture(t_game *g, double alpha, t_vec dist, int x);
//render_utils
void	get_side(t_game *g, t_vec rayDir);
void	ft_get_ray_direction(double alpha, t_vec *rayDir);
void	ft_get_proj_top_bottom(t_game *g, int *top, int *bottom);
//math
double	ft_pythg(double x1, double x2, double y1, double y2);
double	ft_convert_deg_to_rad(double deg);
void	ft_get_floor_values(t_vec hit, int *x, int *y);
//buffer_utils
void	ft_clear_buffer(unsigned int **b, t_game *g);
void	ft_populate_buffer(t_game *g, double proj_h, int x);
int		ft_ceiling(unsigned int	**buffer, int i, int k);
int		ft_floor(unsigned int **buffer, int i, int k, t_game *g);

#endif 