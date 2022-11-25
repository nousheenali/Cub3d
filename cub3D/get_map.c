#include "raycaster.h"

void	get_map_size(t_map *m, int fd)
{
	char *ln;

	ln = get_next_line(fd);
	m->wt = ft_strlen(ln);
	
	while (ln)
	{
		ln = get_next_line(fd);
		m->ht++;
	}
	close(fd);
}

char *get_ln(char *ln)
{
	char	*new;
	int		i;

	i = -1;
	new = malloc(sizeof(char) * ft_strlen(ln));
	while (ln[++i] != '\n' && ln[i] != '\0')
	{
		new[i] = ln[i];
	}
	new[i] = '\0';
	return (new);
}

void print_map(t_map m)
{
	
	for(int i = 0; i < m.ht; i++)
	{
		for(int j = 0; j < m.wt; j++)
		{
			printf("%c", m.map[i][j]);
		}
		printf("\n");
	}
}

void ft_init(t_map *m)
{
	m->map = NULL;
	m->wt = 0.0;
	m->ht = 0.0;
}

void ft_read_map(t_game *g, char *map_name)
{
	int fd;
	int	i;
	int j;


	j = - 1;
	fd = open(map_name, O_RDONLY);
	ft_init(&g->map);
	get_map_size(&g->map, fd);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	while (++j < i)
	{
		g->map.map[j] = get_ln(get_next_line(fd));
	}
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
	
	close(fd);
	// print_map(g->map);
}
