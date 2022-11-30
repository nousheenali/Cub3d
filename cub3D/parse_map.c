#include "raycaster.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ch;

	ch = (char *)s;
	i = 0;
	while (*ch != '\0')
	{
		ch++;
		i++;
	}
	if (c == '\0')
		return (ch);
	while (i >= 0)
	{
		if (*ch == (char)c)
			return (ch);
		ch--;
		i--;
	}
	return (NULL);
}

void ft_valid_name(t_game *g, char *m_name)
{
	int fd;

	if (ft_strrchr(m_name, '.'))
	{
		if (ft_strncmp(ft_strrchr(m_name, '.'), ".cub", 5) || ft_strlen(m_name) == 4)
			ft_error(g, "Map name invalid!\n");
	}
	else
		ft_error(g, "Map name invalid! Map should have .cub extension\n");
	if ((fd = open(m_name, O_RDONLY)) < 0)
		ft_error(g, strerror(errno));
	close(fd);
}

void ft_valid_map(t_game *g)
{
    for(int i = 0; i < (int)(g->map.ht / GRID); i++)
    {
        for (int j = 0; j <= (int)(g->map.wt/GRID); j++)
        {
            if (g->map.map[i][j] != '1' && g->map.map[i][j] != '0' \
				&& g->map.map[i][j] != ' ' && (g->map.map[i][j] != '\n' \
				&& g->map.map[i][j] != '\0') && (g->map.map[i][j] != 'N' \
				&& g->map.map[i][j] != 'S' && g->map.map[i][j] != 'E' && g->map.map[i][j] != 'W'))
            {
                ft_error(g, "Invalid map content!!\n");
            }
        }
    }
}


void check_closed_walls_top(t_game *g)
{
	int i = -1, j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (g->map.map[++i])
	{
		j = 0;
		len = strlen(g->map.map[i]);
		while(++j < len-1)
		{
			if(g->map.map[i][j] == ' ')
			{ 
				while (flag == 0 && (i+n) < (int)g->map.ht/64)
				{
				if (g->map.map[i][j + 1] == '1')
				{
					a = g->map.map[i+n][j-1];
					b = g->map.map[i+n][j];
					c = g->map.map[i+n][j + 1];
					if (a != '1' && b != '1' && c != '1')
						ft_error(g, "+map error");
					else if (a == '1' && c == '1' && b != '1')
						n++;
					else if (a == '1' && b == '1' && c == '1')
						flag = 1 ;
					else
						ft_error(g, "*map error");
				}
				}
			}
		}
		// if (j == len - 1 && i == 0)
		// 	if (g->map.map[i][j-1] != '1' || g->map.map[i+1][j] != '1' || g->map.map[i][j] != '1')
		// 		ft_error(g, "-map error");
	}
}

void check_closed_walls_bot(t_game *g)
{
	int i = (int)g->map.ht/64;
	int j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (--i > 0)
	{
		j = 0;
		len = strlen(g->map.map[i]);
		while(++j < len-1)
		{
			if(g->map.map[i][j] == ' ')
			{ 
				while (flag == 0 && (i-n) > 1)
				{
					if (g->map.map[i][j + 1] == '1')
					{
						a = g->map.map[i-n][j-1];
						b = g->map.map[i-n][j];
						c = g->map.map[i-n][j + 1];
						if (a != '1' && b != '1' && c != '1')
							ft_error(g, "++map error");
						else if (a == '1' && c == '1' && b != '1')
							n++;
						else if (a == '1' && b == '1' && c == '1')
							flag = 1 ;
						else
							ft_error(g, "**map error");
				}
				}
			}
		}
	}
}

void check_closed_walls_r(t_game *g)
{
	int i = 0;
	int j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (g->map.map[++i])
	{
		j = 0;
		len = strlen(g->map.map[i]);
		while (g->map.map[i][j] == 'x')
		{
			j++;
		}
		if (g->map.map[i][j] != '1')
		{
			while (flag == 0 && (i+n) < (int)g->map.ht/64)
			{
				printf("%d %d %c\n", i, j, g->map.map[i][j]);
				a = g->map.map[i-1][j+n];
				b = g->map.map[i][j+n];
				c = g->map.map[i-1][j+n];
				if (a != '1' && b != '1' && c != '1')
					ft_error(g, "+++map error");
				else if (a == '1' && c == '1' && b != '1')
					n++;
				else if (a == '1' && b == '1' && c == '1')
					flag = 1 ;
				else
					ft_error(g, "***map error");
			}
		}
	}
}

void check_closed_walls_l(t_game *g)
{
	int i = 0;
	int j = 0, len = 0;
	char a, b, c;
	int n = 1;
	int flag = 0;

	while (g->map.map[++i])
	{
		len = strlen(g->map.map[i]);
		j = len - 1;
		if (g->map.map[i][j] != '1')
		{
			while (flag == 0 && (i+n) < (int)g->map.ht/64)
			{
				a = g->map.map[i-1][j+n];
				b = g->map.map[i][j+n];
				c = g->map.map[i-1][j+n];
				if (a != '1' && b != '1' && c != '1')
					ft_error(g, "++++map error");
				else if (a == '1' && c == '1' && b != '1')
					n++;
				else if (a == '1' && b == '1' && c == '1')
					flag = 1 ;
				else
					ft_error(g, "****map error");
			}
		}
	}
}

void check_init_space(t_game *g)
{
	int i = 0;
	int j = 0;

	while(g->map.map[i])
	{
		j = 0;
		while(g->map.map[i][j] == ' ')
		{
			g->map.map[i][j] = 'x';
			j++;
		}
		i++;
	}
}

void parse_map(t_game *g, char *m_name)
{
	ft_valid_name(g, m_name); //checks extentions .cub
	ft_read_map(g, m_name);	//reads value and stores in g->map
    ft_valid_map(g); //checks for other charcters ----->need to add the texture and player position
	check_init_space(g);
	check_closed_walls_r(g);
	check_closed_walls_l(g);
	check_closed_walls_top(g);
	check_closed_walls_bot(g);
}