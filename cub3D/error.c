/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:11:54 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/07 11:05:12 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_error(t_game *g, char *msg)
{
	printf("%s", msg);
	free (g->buffer);
	exit(1);
}

void	ft_error_before(char *msg)
{
	printf("%s", msg);
	exit(1);
}
