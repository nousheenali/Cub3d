#ifndef RAYCASTER_H
#define RAYCASTER_H

# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define GRID 64
# define PI 3.1416

// extern int map[5][6];

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
	double	ht;
	double	wt;
}t_map;

typedef struct  s_game
{
	void *mlx;		//mls
	void *win;

	int win_ht;		//screen
	int win_wt;

	void *img;		//mlx_image
	int *data;
	int	bits;
	int	lines;
	int	endian;

	t_map map;		//contains map details
	t_pos pos;		//contains ply posi and direc

	unsigned int	**buffer;	//for colors
	
	double 	fov;	//ray
	int		n_rays;
	double	angle;
	double angle_btw_rays;

	// double map_height;
	// double map_width;
	t_vec *hit;
	t_vec init_dist;
	double dist_proj;	//distance to proj palne

}t_game;

//get_map
void ft_read_map(t_game *g, char *map_name);

//hit
double ft_y_axis_hit(t_game *g, float alpha);
double ft_x_axis_hit(t_game *g, float alpha);

//init
void ft_init_variables(t_game *g);
void	ft_create_buffer(t_game *g);

//raycaster
void ft_start(t_game *g);
void start_game(t_game *g);

//main
double ft_convert_deg_to_rad(double deg);

//move
int ft_button(int key, t_game *g);
int ft_close(t_game *g);

//parse_map
void parse_map(t_game *g, char *m_name);
void ft_valid_name(t_game *g, char *m_name);
void ft_valid_map(t_game *g);
void check_closed_walls(t_game *g);

//error
void ft_error(t_game *g, char *msg);


#endif 