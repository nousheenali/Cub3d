/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:43:13 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/03 13:10:26 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict d, const char *restrict s, size_t d_size)
{
	unsigned int	i;
	int				srclen;

	i = 0;
	if (d_size > 0)
	{
		while (s[i] != '\0')
		{
			d[i] = s[i];
			i++;
			if (i == d_size)
			{
				i--;
				break ;
			}
		}
		d[i] = '\0';
	}
	srclen = ft_strlen(s);
	return (srclen);
}
