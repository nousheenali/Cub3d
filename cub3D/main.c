# include "minilibx/mlx.h"
# include <stdlib.h>
#include "raycaster.h"
# include <math.h>

int map[640][480]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void ft_init_variables(t_game *g)
{
	g->px = 22;
	g->py = 12;
	g->dx = -1;
	g->dy = 0;
	g->planex = 0;
	g->planey = 0.66;
	g->hit = 0;
}

//Distance between x to x and y to y.
void ft_delta_cal(t_game *g)
{
	if (g->rayDirX == 0)
		g->deltaX = 1e30;
	else
		g->deltaX = abs(1 / g->rayDirX);
	if (g->rayDirY == 0)
		g->deltaY = 1e30;
	else
		g->deltaY = abs(1 / g->rayDirY);
}

//to calculate steps and initial side distance  
void ft_step_cal(t_game *g)
{
	if (g->rayDirX < 0)
      {
        g->stepX = -1;
        g->sideX = (g->px - g->mapx) * g->deltaX;
      }
      else
      {
        g->stepX = 1;
        g->sideX = (g->mapx + 1.0 - g->px) * g->deltaX;
      }
      if (g->rayDirY < 0)
      {
        g->stepY = -1;
        g->sideY = (g->py - g->mapy) * g->deltaY;
      }
      else
      {
        g->stepY = 1;
        g->sideY = (g->mapy + 1.0 - g->py) * g->deltaY;
      }
}
 
//DDA algorithm
void ft_dda(t_game *g)
{
	while (g->hit == 0)
	{
		if (g->sideX < g->sideY)
		{
			g->sideX += g->deltaX;
			g->mapx += g->stepX;
			g->side_flag = 0;
		}
		else
		{
			g->sideY += g->deltaY;
			g->mapy += g->stepY;
			g->side_flag = 1;
	
		}
		if (map[g->mapx][g->mapy] > 0)
			g->hit = 1;
	}
}

//to calculate the camare plane
void start_game(t_game *g)
{
	int i = 0;
	while (i < g->win_wt)
	{
		g->camx = 2 * i / (double)g->win_wt - 1;
		g->rayDirX = g->dx + g->planex * g->camx;
		g->rayDirY = g->dy + g->planey * g->camx;

	g->mapx = (int)g->px;
	g->mapy = (int)g->py;

	ft_delta_cal(g);
	ft_step_cal(g);
	ft_dda(g);
		i++;
	}
}

int main()
{
	t_game g;
	g.win_ht = 480;
	g.win_wt = 640;
	ft_init_variables(&g);

	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.win_wt, g.win_ht, "cuB3d");
	start_game(&g);
	mlx_loop(g.mlx);
}