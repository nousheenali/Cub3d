/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:50 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/16 12:56:43 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	get_west(t_game *g, char *ln)
{
	char	*trim;

	trim = ft_strtrim(&ln[3], " \t");
	if (ln[0] == 'W' && ln[1] == 'E' && (ln[2] != ' ' && ln[2] != '\t'))
	{
		ft_error_before(g, "Error: Invalid Entry for West!!\n");
		free(trim);
		return (1);
	}
	else if (ln[0] == 'W' && ln[1] == 'E' && (ln[2] == ' ' || ln[2] == '\t'))
	{
		if (g->wall1.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Error: Invalid or duplicate Entry!!\n");
			free(trim);
			return (1);
		}
		g->wall1.path = trim;
	}
	return (0);
}

int	get_east(t_game *g, char *ln)
{
	char	*trim;

	trim = ft_strtrim(&ln[3], " \t");
	if (ln[0] == 'E' && ln[1] == 'A' && (ln[2] != ' ' && ln[2] != '\t'))
	{
		ft_error_before(g, "Error: Invalid Entry for East111!!\n");
		free(trim);
		return (1);
	}
	else if (ln[0] == 'E' && ln[1] == 'A' && (ln[2] == ' ' || ln[2] == '\t'))
	{
		if (g->wall2.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Error: Invalid or duplicate Entry!!\n");
			free(trim);
			return (1);
		}
		g->wall2.path = trim;
	}
	return (0);
}

int	get_south(t_game *g, char *ln)
{
	char	*trim;

	trim = ft_strtrim(&ln[3], " \t");
	if (ln[0] == 'S' && ln[1] == 'O' && (ln[2] != ' ' && ln[2] != '\t'))
	{
		ft_error_before(g, "Error: Invalid Entry for South!!\n");
		free(trim);
		return (1);
	}
	else if (ln[0] == 'S' && ln[1] == 'O' && (ln[2] == ' ' || ln[2] == '\t'))
	{
		if (g->wall3.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Error: Invalid or duplicate Entry!!\n");
			free(trim);
			return (1);
		}
		g->wall3.path = trim;
	}
	return (0);
}

int	get_north(t_game *g, char *ln)
{
	char	*trim;

	trim = ft_strtrim(&ln[3], " \t");
	if (ln[0] == 'N' && ln[1] == 'O' && (ln[2] != ' ' && ln[2] != '\t'))
	{
		ft_error_before(g, "Error: Invalid Entry for North!!\n");
		free(trim);
		return (1);
	}
	else if (ln[0] == 'N' && ln[1] == 'O' && (ln[2] == ' ' || ln[2] == '\t'))
	{
		if (g->wall4.path || ft_strncmp(trim, "./textures/", 11))
		{
			ft_error_before(g, "Error: Invalid or duplicate Entry!!\n");
			free(trim);
			return (1);
		}
		g->wall4.path = trim;
	}
	return (0);
}

int	ft_get_texture(t_game *g, char *ln)
{
	if (ln[0] == 'E')
	{
		if (get_east(g, ln))
			return (1);
	}
	if (ln[0] == 'W')
	{
		if (get_west(g, ln))
			return (1);
	}
	if (ln[0] == 'N')
	{
		if (get_north(g, ln))
			return (1);
	}
	if (ln[0] == 'S')
	{
		if (get_south(g, ln))
			return (1);
	}
	return (0);
}
