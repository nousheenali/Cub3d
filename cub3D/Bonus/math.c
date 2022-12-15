/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:05:56 by nali              #+#    #+#             */
/*   Updated: 2022/12/07 14:26:45 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

double	ft_pythg(double x1, double x2, double y1, double y2)
{
	return (sqrt(((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1))));
}

double	ft_convert_deg_to_rad(double deg)
{
	return (deg * PI / 180.0);
}

void	ft_get_floor_values(t_vec hit, int *x, int *y)
{
	*x = floor(hit.x / GRID);
	*y = floor(hit.y / GRID);
}

double	limit_ang(double a)
{
	if (a > 359.00)
		a -= 359.00;
	else if (a < 0.00)
		a += 359.00;
	return (a);
}
