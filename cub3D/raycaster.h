#ifndef RAYCASTER_H
#define RAYCASTER_H

# define GRID 64
# define PI 3.1416

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

#endif 