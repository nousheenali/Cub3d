#ifndef RAYCASTER_H
#define RAYCASTER_H

typedef struct  s_game
{
	void *mlx;
	void *win;

	int win_ht;
	int win_wt;


	char **map;
	double px;
	double py;
	double dx;
	double dy;
	double planex;
	double planey;

	double camx;
	double rayDirX;
	double rayDirY;	

	int mapx;
	int mapy;
	double sideX;
	double sideY;
	double deltaX;
	double deltaY;
	int stepX;
	int stepY;

	int hit;
	int side_flag;


}t_game;



#endif 