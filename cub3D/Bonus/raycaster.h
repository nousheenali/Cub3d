/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:53:47 by nali              #+#    #+#             */
/*   Updated: 2022/12/15 13:22:06 by sfathima         ###   ########.fr       */
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
	char	*path;
}				t_data;

typedef struct s_game
{
	void			*mlx;
	void			*win;

	int				win_ht;
	int				win_wt;

	void			*img;
	int				*data;
	int				bits;
	int				lines;
	int				endian;

	t_map			map;

	unsigned int	**buffer;

	double			proj_h;
	int				side;
	double			fov;
	int				n_rays;
	double			angle;
	double			angle_btw_rays;

	t_vec			*hit;
	t_vec			init_dist;
	double			dist_proj;
	t_data			wall1;
	t_data			wall2;
	t_data			wall3;
	t_data			wall4;
}t_game;

//get_map1
int		ft_read_map(t_game *g, char *map_name);
//get_map2
int		get_floor(char *ln, t_game *g);
int		get_ceiling(char *ln, t_game *g);
void	get_details(char *ln, t_game *g, char *ln1);
int		check_line(char *ln, t_game *g);
void	check_floor_ce(t_game *g);
//get_map3
void	skip_line(int ct, int fd);
int		get_map_size(t_map *m, char *ln, int ct);
void	clear_texture(t_game *g, int *ct, int *flag);
int		ceiling_floor_tests(char **c, t_game *g);
int		ft_count_char(char const *s, char c);
//get_map4
int		get_east_west(t_game *g, char *ln);
int		get_north_south(t_game *g, char *ln);
int		ft_get_texture(t_game *g, char *ln);
//hit
double	ft_y_axis_hit(t_game *g, float alpha);
double	ft_x_axis_hit(t_game *g, float alpha);
//init
void	ft_create_buffer(t_game *g);
void	ft_valid_ply(t_game *g);
void	ft_init_variables(t_game *g);
void	ft_init(t_map *m);
//load_textures
int		ft_convert_xpm_to_img(t_game *g);
//math
double	ft_pythg(double x1, double x2, double y1, double y2);
double	ft_convert_deg_to_rad(double deg);
void	ft_get_floor_values(t_vec hit, int *x, int *y);
double	limit_ang(double a);
//move
int		ft_button(int key, t_game *g);
int		ft_close(t_game *g);
int		mouse_events(int x, int y, t_game *g, t_vec t);
//parse_map
int		ft_valid_name(char *m_name);
int		ft_valid_map(t_game *g);
void	ft_2darray(void **c);
int		parse_map(t_game *g, char *m_name);
//parse_map2
void	check_closed_walls(t_game *g);
void	check_wall_all_dir(t_game *g);
void	check_for_wall(t_vec t, t_game *g);
//player
void	set_ang(t_game *g, int i, int j);
void	ft_find_ply_posi(t_game *g);
//raycaster
void	ft_start(t_game *g);
void	start_game(t_game *g);
//render_texture
void	ft_texture(t_game *g, double alpha, t_vec dist, int x);
//render_utils
void	get_side(t_game *g, t_vec rayDir);
void	ft_get_ray_direction(double alpha, t_vec *rayDir);
void	ft_get_proj_top_bottom(t_game *g, int *top, int *bottom);
//ft_atoi_cube
int		ft_atoi_c(const char *str);
//error
void	ft_free_map(t_game *g);
void	ft_error(t_game *g, char *msg);
void	ft_error_before(t_game *g, char *msg);
void	ft_error_exit(t_game *g, char *msg);
void	ft_exit_check_line(char *ln, char *ln1);
//buffer_utils
void	ft_clear_buffer(unsigned int **b, t_game *g);
void	ft_populate_buffer(t_game *g, double proj_h, int x);
int		ft_ceiling(unsigned int	**buffer, int i, int k);
int		ft_floor(unsigned int **buffer, int i, int k, t_game *g);
void	print_map(t_game *g);

#endif 