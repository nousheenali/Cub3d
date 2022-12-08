/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:11:54 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 09:48:20 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_error(t_game *g, char *msg)
{
	int	i;

	i = 0;
	while (g->buffer[i])
		free (g->buffer[i++]);
	free (g->map.map);
	printf("%s", msg);
	exit(1);
}

void	ft_error_before(t_game *g, char *msg)
{
	// if (g->wall1.path)
	// 	free(g->wall1.path);
	// if (g->wall2.path)
	// 	free(g->wall2.path);
	// if (g->wall3.path)
	// 	free(g->wall3.path);
	// if (g->wall4.path)
	// 	free(g->wall4.path);
	// if (g->map.map)
	// 	free(g->map.map);
	printf("%s", msg);
	exit(1);
}
