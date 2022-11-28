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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (strlen(s) < start)
		return (strdup(""));
	if (start + len > strlen(s))
		len = strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[start] && j < len)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start_index;
	size_t	end_index;

	if (!s1)
		return (NULL);
	start_index = 0;
	end_index = strlen(s1) - 1;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	while (end_index >= start_index && ft_strchr(set, s1[end_index]))
		end_index--;
	str = ft_substr(s1, start_index, (end_index - start_index + 1));
	return (str);
}

void ft_valid_map(t_game *g)
{
    for(int i = 0; i < (int)(g->map.ht / GRID); i++)
    {
        for (int j = 0; j <= (int)(g->map.wt/GRID); j++)
        {
            if (g->map.map[i][j] != '1' && g->map.map[i][j] != '0' && g->map.map[i][j] != ' ' && (g->map.map[i][j] != '\n' && g->map.map[i][j] != '\0')) // add player posi
            {
                ft_error(g, "Invalid map content!!\n");
            }
        }
    }
}

int	walls_spaces_only(char *temp)
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

void check_closed_walls_hori(t_game *g)
{
	char	*temp;
	int		i;
	int		flag;

	i = 0;
	while (g->map.map[i])
	{
		// printf("map %s %d %f\n", g->map.map[i], i, g->map.ht);
		temp = ft_strtrim(g->map.map[i], " ");
		printf("%d %s\n", i, temp);
		if (temp[0] != '1' || temp[strlen(temp) - 1] != '1')
			flag = 1;
		if (i == 0)
			if (walls_spaces_only(temp))
				flag = 1;
		if (i == (g->map.ht/GRID) - 1)
			if (walls_spaces_only(temp))
				flag = 1;
		i++;
		free(temp);
		if (flag == 1)
			ft_error(g, "Map not surrounded by walls!!");
	}
}

void check_closed_walls_ver(t_game *g)
{
	char	*temp;
	int		i;
	int		flag;

	i = 0;
	while (g->map.map[i])
	{
		// printf("map %s %d %f\n", g->map.map[i], i, g->map.ht);
		temp = ft_strtrim(g->map.map[i], " ");
		printf("%d %s\n", i, temp);
		if (temp[0] != '1' || temp[strlen(temp) - 1] != '1')
			flag = 1;
		if (i == 0)
			if (walls_spaces_only(temp))
				flag = 1;
		if (i == (g->map.ht/GRID) - 1)
			if (walls_spaces_only(temp))
				flag = 1;
		i++;
		free(temp);
		if (flag == 1)
			ft_error(g, "Map not surrounded by walls!!");
	}
}

void parse_map(t_game *g, char *m_name)
{
	ft_valid_name(g, m_name); //checks extentions .cub
	ft_read_map(g, m_name);	//reads value and stores in g->map
    ft_valid_map(g); //checks for other charcters ----->need to add the texture and player position
	check_closed_walls_hori(g);
	check_closed_walls_ver(g);
}