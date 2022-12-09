/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:24 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 15:31:19 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_exit_check_line(char *ln, char *ln1, int fd)
{
	free(ln1);
	free(ln);
	close(fd);
	exit(1);
}

void	check_mandatory_elements(t_game *g, char *ln, char *ln1, int fd)
{
	if (ln1[0] == 'N' || ln1[0] == 'S' || ln1[0] == 'E' || ln1[0] == 'W')
	{
		if (ft_get_texture(g, ln1))
			ft_exit_check_line(ln, ln1, fd);
	}
	if (ln1[0] == 'F')
	{
		if (get_floor(ln, g))
			ft_exit_check_line(ln, ln1, fd);
	}
	else if (ln1[0] == 'C')
	{
		if (get_ceiling(ln, g))
			ft_exit_check_line(ln, ln1, fd);
	}
}

void	check_invalid_elements(t_game *g, char *ln, char *ln1, int fd)
{
	if (ln1[0] != '1' && ln1[0] != '\n' && ln1[0] != 'N' && ln1[0] != ' ' && \
	ln[0] != 'S' && ln1[0] != 'E' && ln1[0] != 'W' && ln1[0] != 'F' && \
	ln1[0] != 'C')
	{
		ft_error_before(g, "Invalid map content!!");
		ft_exit_check_line(ln, ln1, fd);
	}
}

void	check_space_tabs(t_game *g, char *ln, char *ln1, int fd)
{
	char	*trim;

	if (ln1[0] == ' ' || ln1[0] == '\t')
	{
		trim = ft_strtrim(ln1, " ");
		if (trim[0] != '1')
		{
			free(trim);
			ft_error_before(g, "Invalid map content!!");
			ft_exit_check_line(ln, ln1, fd);
		}
		free(trim);
	}
}

int	check_line(char *ln, t_game *g, int fd)
{
	char	*ln1;

	ln1 = malloc(sizeof(char) * strlen(ln));
	ft_strlcpy(ln1, ln, strlen(ln));
	check_mandatory_elements(g, ln, ln1, fd);
	check_invalid_elements(g, ln, ln1, fd);
	if (ln1[0] == 'N' || ln1[0] == 'S' || ln1[0] == 'E'
		|| ln1[0] == 'W' || ln1[0] == 'F' || ln1[0] == 'C')
	{
		free(ln1);
		return (1);
	}
	check_space_tabs(g, ln, ln1, fd);
	free(ln1);
	return (0);
}
