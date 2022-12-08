/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:11:54 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 10:46:00 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_free_map(t_game *g)
{
	int	i;

	i = -1;
	while (g->map.map[++i])
		free(g->map.map[i]);
	free(g->map.map);
}

void	ft_error(t_game *g, char *msg)
{
	int	i;

	i = -1;
	while (g->buffer[++i])
		free (g->buffer[i]);
	free(g->buffer);
	ft_free_map(g);
	printf("%s", msg);
	exit(1);
}

void	ft_error_before(t_game *g, char *msg)
{
	if (g->wall1.path)
		free(g->wall1.path);
	if (g->wall2.path)
		free(g->wall2.path);
	if (g->wall3.path)
		free(g->wall3.path);
	if (g->wall4.path)
		free(g->wall4.path);
	ft_free_map(g);
	printf("%s", msg);
	exit(1);
}
