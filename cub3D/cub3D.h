#ifndef CUB3D_H
#define CUB3D_H

# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define GRID 64
# define PI 3.1416

typedef struct  s_vec
{
	double x;
	double y;
	double a;
}t_vec;

typedef struct  s_axis
{
	double x;
	double y;
}t_axis;

typedef struct  s_pos
{
	t_axis ax;
	t_vec	vc;
}t_pos;

typedef struct  s_map
{
	char **map;
	int	ht;
	int	wt;
}t_map;

typedef struct  s_game
{
	void *mlx;			//mls
	void *win;

	int win_ht;			//screen
	int win_wt;

	void *img;			//mlx_image
	int *data;
	int	bits;
	int	lines;
	int	endian;

	t_map map;			//contains map details
	t_pos pos;			//contains ply posi and direc

	unsigned int	**buffer;	//for colors
	
	double 	fov;		//ray
	int		n_rays;
	double	angle;
	double angle_btw_rays;

	t_vec *hit;
	t_vec init_dist;
	double dist_proj;	//distance to proj palne

}t_game;

//get_map
void ft_read_map(t_game *g, char *map_name);

//init
void ft_init_variables(t_game *g);

//math
double ft_deg_to_rad(double deg);

//raycaster
void ft_start(t_game *g);

//move
int ft_button(int key, t_game *g);

#endif