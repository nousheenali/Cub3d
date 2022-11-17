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

	char **map;
	t_vec pos;
	t_vec init_dist;
	double angle;
	double fov;
	double angle_btw_rays;


}t_game;

#endif 