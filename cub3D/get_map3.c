/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:50:01 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/08 15:31:53 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	skip_line(int ct, int fd)
{
	char	*ln;

	while (--ct > 0)
	{
		ln = get_next_line(fd);
		free(ln);
	}
}

int	get_map_size(t_map *m, char *ln, int ct)
{
	if (m->wt < (double)ft_strlen(ln))
		m->wt = ft_strlen(ln);
	m->ht++;
	return (ct - 1);
}

void	clear_texture(t_game *g, int *ct, int *flag)
{
	*ct = 0;
	*flag = 0;
	g->wall1.path = NULL;
	g->wall2.path = NULL;
	g->wall3.path = NULL;
	g->wall4.path = NULL;
	g->map.fl = 0;
	g->map.ce = 0;
}
