/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:41:19 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/14 10:18:19 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static int	ft_check(unsigned long n)
{
	if (n >= 2147483648UL)
		return (-1);
	else
		return (n);
}

const char	*skip_spaces_tabs(const char *str)
{
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	return (str);
}

int	ft_atoi_c(const char *str)
{
	unsigned long	n;

	n = 0;
	str = skip_spaces_tabs(str);
	if (!*str || (*str == '-') || (*str == '+'))
		return (-1);
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
			n = (n * 10) + (*str - '0');
		else
		{
			if (*str == '\n' || *str == '\0')
				break ;
			else
				return (-1);
		}
		str++;
	}
	n = ft_check(n);
	return (n);
}
