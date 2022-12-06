#include "raycaster.h"

void get_floor(char *ln, t_map *m)
{
	printf("%s", ln);
	// if (ln[0] == 'F')
	// ft_split()

}

int	get_map_size(t_map *m, int fd)
{
	char *ln;
	int ct = 0;

	ln = get_next_line(fd);
	while (strcmp(ln, "\n")) // textures
	{
		ln = get_next_line(fd);
		ct++;
	}

	while (!strcmp(ln, "\n"))
		ln = get_next_line(fd); //floor
	// get_floor(ln, m);
	
	ct++;
	while (strcmp(ln, "\n")) //ceiling
	{
		ln = get_next_line(fd);
		ct++;
	}
	ln = get_next_line(fd);
	m->wt = ft_strlen(ln);
	while (ln)
	{
		ln = get_next_line(fd);
		if (ln && m->wt < (double)ft_strlen(ln))
			m->wt = ft_strlen(ln);
		m->ht++;
	}
	close(fd);
	return (ct);
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
	int ct;
	char *ln;


	j = - 1;
	fd = open(map_name, O_RDONLY);
	ft_init(&g->map);
	ct = get_map_size(&g->map, fd);
	g->map.map = malloc(sizeof(char *) * g->map.ht + 1);
	g->map.map[(int)g->map.ht] = NULL;
	fd = open(map_name, O_RDONLY);
	i = g->map.ht;
	while (ct >= 0)
	{
		ln = get_next_line(fd);
		ct--;
	}
	while (++j < i)
		g->map.map[j] = get_ln(get_next_line(fd));
	g->map.ht = g->map.ht * 64.0;
	g->map.wt = (g->map.wt - 1) * 64.0;
	close(fd);
}
