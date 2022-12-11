#include "raycaster.h"

int	contain_walls_or_spaces_only(char *temp)
{
	int	j;

	j = 0;
	while (temp[j])
	{
		if (temp[j] != '1' && temp[j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

void	check_closed_walls(t_game *g)
{
	int		i;
	int		flag;
	char	*temp;

	i = 0;
	flag = 0;

	while (g->map.map[i])
	{
		temp = ft_strtrim(g->map.map[i], "x");
		if (temp[0] != '1' || temp[ft_strlen(temp) - 1] != '1')
			flag = 1;
		if (i == 0)
			if (contain_walls_or_spaces_only(temp))
				flag = 1;
		if (i == ((int)g->map.ht/64 - 1))
			if (contain_walls_or_spaces_only(temp))
				flag = 1;
		free(temp);
		if (flag == 1)
		{
			ft_error_before(g, "Map Not Closed by walls!");
			exit(1);
		}
		i++;
	}
}

void ft_error_exit(t_game *g, char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	check_before_space(t_game *g, int i, int j)
{
	if (i + 1 < (int)g->map.ht /64)
		if (g->map.map[i + 1][j] != ' ' && g->map.map[i + 1][j] != '1')
			ft_error_exit(g, "Map not closed by walls!!!");
	if (i - 1 >= 0)
		if (g->map.map[i - 1][j] != ' ' && g->map.map[i - 1][j] != '1')
			ft_error_exit(g, "Map not closed by walls!!!");
	if (j + 1 < (int)g->map.wt/64)
		if (g->map.map[i][j + 1] != ' ' && g->map.map[i][j + 1] != '1')
			ft_error_exit(g, "Map not closed by walls!!!");
	if (j - 1 >= 0)
		if (g->map.map[i][j - 1] != ' ' && g->map.map[i][j - 1] != '1')
			ft_error_exit(g, "Map not closed by walls!!!");
}

void	check_wall_all_dir(t_game *g)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (g->map.map[i])
	{
		j = 0;
		temp = g->map.map[i];
		while (g->map.map[i][j])
		{
			if (temp[j] == ' ')
			{	
				check_before_space(g, i, j);
			}
			j++;
		}
		i++;
	}
}