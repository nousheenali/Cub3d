#ifndef RAYCASTER_H
#define RAYCASTER_H


# include "minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>
#include <stdio.h>

# define GRID 64
# define PI 3.1416

extern int map[5][6];

typedef struct  s_vec
{
	double x;
	double y;
}t_vec;


typedef struct  s_game
{
	void *mlx;
	void *win;

	int win_ht;
	int win_wt;

	void *img;
	int *data;
	int	bits;
	int	lines;
	int	endian;


	char **map;
	t_vec pos;
	t_vec init_dist;
	double angle;
	double fov;
	double angle_btw_rays;
	double dist_proj; //distance to proj palne

	unsigned int	**buffer;

}t_game;

//main.c
double ft_convert_deg_to_rad(double deg);
//hit.c
double ft_x_axis_hit(t_game *g, float alpha);
double ft_y_axis_hit(t_game *g, float alpha);


#endif 